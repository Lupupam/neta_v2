#include <control.h>
#include <omnetpp.h>
#include <string>
#include <iostream>
#include <math.h>
#include <FWMath.h>
#include <random>
#include "LineSegmentsMobilityBase.h"
#include "ChannelControl.h"

Define_Module(control);

//-----PROCESOS DE INICIALIZACI�N Y DE PROGRAMACION DE MENSAJES-----//
void control::initialize() {
    getNodosAgente();
    getNodosUsuario();
    updateInterval = par("updateInterval").doubleValue() ;
    maxSpeed = par("MaxSpeed").doubleValue();
    Nparticulas = par("Nparticulas") ;
    iteMax = par("iterMax") ;

    // Datos necesarios para calcular la distancia de cobertura

    fPortadora = par("carrierFreq").doubleValue()*1e9 ;
    potMaxTX = par("potenciaMax").doubleValue()*1e-4 ;
    alpha = par("alpha").doubleValue() ;
    sensibilidad = FWMath::dBm2mW(par("sensibilidad").doubleValue() )*1e-4  ;

    distanciaCobertura = calcDistCobertura( fPortadora , alpha , sensibilidad , potMaxTX ) ;

    ConectividadNoAgentes.setName("No Agentes") ;
    ConectividadSiAgentes.setName("Si Agentes") ;
    ConectividadNoAgentesStats.setName("No Agentes Stats") ;
    ConectividadSiAgentesStats.setName("Si Agentes Stats") ;

    bool activado=false;
    cMessage *msg = new cMessage("ESTADISTICAS");
    scheduleAt(simTime()+1.0, msg);


}

void control::initializeDefense(){
    if (activado==false){
        Enter_Method_Silent();
        EV << "------------------------------------\n";
        EV << "AQUI EMPIEZA TODO...................";
        EV << "La distancia de Cobertura es : " << distanciaCobertura << " m\n";
        EV << "------------------------------------\n";
        cMessage *msg = new cMessage("MSG");
        scheduleAt(simTime()+1.0, msg);
        activado=true;
    }
}

double control::calcDistCobertura(double f, double a, double s , double p){
    double dist, lambda ;

    lambda = ( V_LUZ / f ) ;
    dist =pow(lambda * lambda * p / (16.0 * M_PI * M_PI * s), 1.0 / a);

    return dist ;
}

void control::getNodosAgente() {
   cTopology topoA; //Used to discover the topology of the node and find modules for activating the attack
   cTopology::Node *nodo;

   std::string nombreNodo;
   std::string prefix;

   topoA.extractByProperty("agente") ;


   EV << "------------------------------------\n";
   EV << "Encontrados " << topoA.getNumNodes() << " nodos agentes\n";
   EV << "------------------------------------\n";

   prefix = this->getParentModule()->getFullPath();

   numAgentes = 0;
   for (int j = 0; j < topoA.getNumNodes(); j++) {
          nodo = topoA.getNode(j);
          nombreNodo = nodo->getModule()->getFullPath();
//          if (not nombreNodo.compare(0, prefix.size(), prefix)) {
              EV << "--->Insertado el Agente: " << nombreNodo << "\n";
              listaAgentes.push_back(check_and_cast<mobilityAgente *>(nodo->getModule()));
              numAgentes++;
          }
//   }

}

void control::getNodosUsuario() {
    cTopology topoU; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *nodo;

    std::string nombreNodo;
    std::string prefix;
    listaUsuarios.clear();

    topoU.extractByProperty("usuario") ;

    EV << "------------------------------------\n";
    EV << "Encontrados " << topoU.getNumNodes() << " nodos usuarios\n";
    EV << "------------------------------------\n";

    prefix = this->getParentModule()->getFullPath();

    numUsuarios = 0;
    for (int i = 0; i < topoU.getNumNodes(); i++) {
           nodo = topoU.getNode(i);
           nombreNodo = nodo->getModule()->getFullPath();
 //          if (not nombreNodo.compare(0, prefix.size(), prefix)) {
               EV << "--->Insertado el Usuario: " << nombreNodo << "\n";
               listaUsuarios.push_back(check_and_cast<LineSegmentsMobilityBase *>(nodo->getModule()));
               numUsuarios++;
           }
 //   }

}

void control::handleMessage(cMessage *msg){
        double stat1,stat2 ;
        std::vector<movimiento> mov ;
        if (not strcmp(msg->getFullName(),"MSG") && activado==true) {
            delete msg;
            // Obtenemos la posicion de los usuarios y los puntos de atraccion
            particionesUsuarios() ;
            EV << "---> EMPIEZAN LAS PARTICIONES DE USUARIOS ----> \n" ;
            EV << "---> Se han encontrado : "<< listaParticionesU.size() <<" Secciones ---->\n" ;

            getPA();
            EV << " La lista de los puntos de atraccion son " << pAtraccion.size() <<": -------> \n" ;
            for ( int l = 0 ; l < pAtraccion.size() ; l++ ){
                EV << pAtraccion[l].x << "  " << pAtraccion[l].y << "\n";
            }

            mov = pso();
            EV << " El movimiento seleccionado es : \n " ;
            for ( int z = 0 ; z < mov.size() ; z ++) {
                EV << "  ||" << mov[z].modulo << " " << mov[z].angulo << "||" ;
            }
            EV <<"\n" ;
            for( int i = 0 ; i < numAgentes ; i++){
                listaAgentes[i]->moverA(mov[i].modulo,mov[i].angulo) ;
            }
            // Evaluamos la conectividad de la red y la mejora que introducen los agentes
            stat1 = evaluateRed(true) ;
//            stat2 = evaluateRed(true) ;
            ConectividadNoAgentes.record(stat1) ;
//            ConectividadSiAgentes.record(stat2) ;
            ConectividadNoAgentesStats.collect(stat1) ;
//            ConectividadSiAgentesStats.collect(stat2) ;
            double st1 = evaluateRed(false) ;
//            double st2 = evaluateRed(true) ;
            EV << "-----------------RESULTADOS-----------------\n" ;
//            EV << "---O1A = " << st2 << " O1 = "<< st1 << " ---\n" ;
            EV << "---O1 = "<< st1 << " ---\n" ;
            EV << "-----------------RESULTADOS-----------------\n" ;
            // Programamos para que tod se ejecute cada segundo
            cMessage *msg_aux = new cMessage("MSG");
            scheduleAt(simTime()+updateInterval, msg_aux);
        }
    else if (not strcmp(msg->getFullName(),"ESTADISTICAS") && activado==false)
    {
        particionesUsuarios() ;
        // Evaluamos la conectividad de la red sin agentes
        stat1 = evaluateRed(false) ;
//        stat2 = evaluateRed(true) ;
        ConectividadNoAgentes.record(stat1) ;
//        ConectividadSiAgentes.record(stat2) ;
        ConectividadNoAgentesStats.collect(stat1) ;
//        ConectividadSiAgentesStats.collect(stat2) ;
        double st1 = evaluateRed(false) ;
//        double st2 = evaluateRed(true) ;
        EV << "-----------------RESULTADOS-----------------\n" ;
        EV << "----O1 = "<< st1 << " ---\n" ;
        EV << "-----------------RESULTADOS-----------------\n" ;
        // Programamos para que tod se ejecute cada segundo
        cMessage *msg_aux = new cMessage("ESTADISTICAS");
        scheduleAt(simTime()+updateInterval, msg_aux);
    }

}


//-----FUNCIONES UTILIZADAS PARA CALCULAR LAS DISTINTAS PARTICIONES DE LA RED -----//
void control::particionesUsuarios(){
    std::vector< bool > aux ;
    Coord a,b ;

    // Vaciamos todos los posibles vectores
    listaParticionesU.clear() ;
    posUsuarios.clear() ;
    visitados1.clear() ;
    conectados1.clear() ;

    for (int w = 0 ; w < numUsuarios ; w++) {
        visitados1.push_back(false) ;
        posUsuarios.push_back(listaUsuarios[w]->getCurrentPosition()) ;
    }

    for (int i = 0 ; i < numUsuarios ; i++){
        a = posUsuarios[i] ;
        aux.clear() ;
        for (int j = 0 ; j < numUsuarios ; j++){
            b = posUsuarios[j] ;
            if ( a.distance(b) <= distanciaCobertura ) {
                aux.push_back(true) ;
            }
            else {
                aux.push_back(false) ;
            }
        }
        conectados1.push_back(aux) ;
    }

    for (int k = 0 ; k < numUsuarios ; k++ ){
        if (!visitados1[k]){
            dfs1(k) ;
            listaParticionesU.push_back(lista1) ;
            lista1.clear() ;
        }
    }

    EV << "---> EMPIEZAN LAS SECCIONES ---->" ;
    EV << "---> Se han encontrado : "<< listaParticionesU.size() <<" Secciones ---->\n" ;
    for ( int x = 0 ; x < listaParticionesU.size() ; x++ ){
        for ( int y = 0 ; y < listaParticionesU[x].size() ; y++ ){
            EV << listaParticionesU[x][y] << " " ;
        }
        EV << "\n" ;
    }
}

void control::dfs1( int puntero ){
    visitados1[puntero] = true ;
    lista1.push_back(puntero) ;
    for ( int i = 0 ; i < numUsuarios ; i++ ){
        if ( conectados1[puntero][i] && visitados1[i]==0 ) {
            dfs1(i) ;
        }
    }
}

void control::dfs2( int puntero ){
    visitados2[puntero] = true ;
    lista2.push_back(puntero) ;
    for ( int i = 0 ; i < numUsuarios ; i++ ){
        if ( conectados2[puntero][i] && !visitados2[i] ) {
            dfs2(i) ;
        }
    }
}

void control::getPA(){

   double min ;
   Coord a,b,pAux ;
   pAtraccion.clear();

   for ( int i = 0 ; i < listaParticionesU.size() - 1 ; i++ ) {
        for( int j = i+1 ; j < listaParticionesU.size() ; j++ ) {
            min = std::numeric_limits<double>::max();
            for(int k = 0 ; k < listaParticionesU[i].size() ; k++ ){
                a = listaUsuarios[listaParticionesU[i][k]]->getCurrentPosition();
                for( int m = 0 ; m < listaParticionesU[j].size() ; m++ ){
                    b = listaUsuarios[listaParticionesU[j][m]]->getCurrentPosition();
                    if (a.distance(b) <= min){
                        min = a.distance(b) ;
                        pAux.x =  a.x + ((b.x - a.x)/2);
                        pAux.y =  a.y + ((b.y - a.y)/2);
                    }

                }
            }
            pAtraccion.push_back(pAux);
        }
   }
}

 void control::initParticulas(){
    movimiento movAux;
    std::vector<movimiento> pAux;
    std::vector<movimiento> iAux;
    std::random_device rd;

    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distParticulaAngulo(0.0,2*M_PI);
    std::uniform_real_distribution<double> distParticulaModulo(0.0,maxSpeed);
    std::uniform_real_distribution<double> distIncrementoAngulo(-2*M_PI,2*M_PI);
    std::uniform_real_distribution<double> distIncrementoModulo(-maxSpeed,maxSpeed);

    particulas.clear() ;
    incrementos.clear() ;

    for ( int i = 0 ; i < Nparticulas ; i++){
        for ( int j = 0 ; j < numAgentes ; j++){
            movAux.modulo = distParticulaModulo(generator) ;
            movAux.angulo = distParticulaAngulo(generator) ;
            pAux.push_back(movAux) ;
            movAux.modulo = distIncrementoModulo(generator) ;
            movAux.angulo = distIncrementoAngulo(generator) ;
            iAux.push_back(movAux) ;
        }
        particulas.push_back(pAux) ;
        incrementos.push_back(iAux) ;
        pAux.clear();
        iAux.clear();
    }
}

std::vector< std::vector<Coord> > control::getPosParticulas(std::vector< std::vector< movimiento > > p){
    double deltaX , deltaY ;
    movimiento movi ;
    Coord pos;
    std::vector< std::vector< Coord > > posParticulas;
    std::vector< Coord > aux ;

    for (int i = 0 ; i < p.size() ; i++ ){
        for ( int j = 0 ; j < p[i].size() ; j++ ){
            movi = p[i][j] ;
            deltaX = movi.modulo * cos(movi.angulo) ;
            deltaY = movi.modulo * sin(movi.angulo) ;

            pos = listaAgentes[j]->getCurrentPosition();
            pos.x += deltaX ;
            pos.y += deltaY ;
            aux.push_back(pos) ;
        }
        posParticulas.push_back(aux) ;
        aux.clear() ;
    }

    return posParticulas ;
}

std::vector< std::vector< int > > control::particiones(std::vector<Coord> posAgentes){
    std::vector<int> agenteConecta ;
    std::vector< std::vector< int > > part ;

    conectados2.clear();
    visitados2.clear();
    lista2.clear();
    conectados2 = conectados1 ;


    for ( int z = 0 ; z < numUsuarios ; z++) visitados2.push_back(false) ;

    for ( int i = 0 ; i < posAgentes.size() ; i++ ){
        for ( int j = 0 ; j < listaParticionesU.size() ; j++){
            for (int k = 0 ; k < listaParticionesU[j].size(); k++){
                if ( posAgentes[i].distance(posUsuarios[listaParticionesU[j][k]]) <= distanciaCobertura){
                    agenteConecta.push_back(k) ;
                }
            }
        }
        for ( int x = 0 ; x < agenteConecta.size() ; x++ ){
            for ( int y = 0 ; y < agenteConecta.size() ; y++){
                if (x != y) conectados2[agenteConecta[x]][agenteConecta[y]] = true ;
            }
        }
        agenteConecta.clear() ;
    }

    for (int k = 0 ; k < numUsuarios ; k++ ){
        if (!visitados2[k]){
            dfs2(k) ;
            part.push_back(lista2) ;
            lista2.clear() ;
        }
    }
    return part ;
}

//-----FUNCIONES OBJETIVO-----//
double control::o1(std::vector<Coord> pParticulas){
    double suma = 0 ;
    double resultado = 0 ;

    std::vector< std::vector< int > > p ;
    p = particiones( pParticulas ) ;
    for ( int i = 0 ; i < p.size() ; i++){
        suma += ( p[i].size() - 1 ) * p[i].size() ;
    }
    resultado = suma /(numUsuarios*(numUsuarios - 1)) ;

    return resultado ;
}

double control::o3(std::vector<Coord> pParticulas){
    double min = std::numeric_limits<double>::max();

    for ( int i = 0 ; i < pParticulas.size() ; i++ ){
        for ( int j = 0 ; j < pAtraccion.size() ; j++ ){
            if ( pParticulas[i].distance(pAtraccion[j]) < min ) min = pParticulas[i].distance(pAtraccion[j]) ;
        }
    }

    return min ;
}

double control::o32(std::vector<Coord> pParticulas){
    double resultado = 0 ;
    double disAgentes  = 0;

    for ( int i = 0 ; i < pParticulas.size() ; i++ ){
        for ( int j = 0 ; j < pAtraccion.size() ; j++ ){
            resultado += pParticulas[i].distance(pAtraccion[j]) ;
        }
    }

    for ( int k = 0 ; k < pParticulas.size() ; k++){
        for ( int n = 0 ; n < pParticulas.size() ; n++ ){
            disAgentes += pParticulas[k].distance(pParticulas[n]) ;
        }
    }

    resultado -= disAgentes ;
    return resultado;

}

//-----FUNCIONES QUE UTILIZAN O1 Y O3 PARA EVALUAR LA BONDAD DE LAS SOLUCIONES-----//
int control::evaluatePopulation(std::vector< std::vector< movimiento > > population){
    std::vector< std::vector< Coord > > posParticulas;
    std::vector<double> aux ;
    int puntero = 0 ;

    resultados.clear() ;
    posParticulas = getPosParticulas(population) ;
    for (int x = 0 ; x < posParticulas.size() ; x++){
        for (int y = 0 ; y < posParticulas[x].size() ; y++){
        }
    }

    pbest = population ;
    for (int i = 0 ; i < posParticulas.size() ; i++ ){
        aux.push_back(o1(posParticulas[i])) ;
        aux.push_back(o32(posParticulas[i])) ;
        resultados.push_back(aux) ;
        aux.clear();
    }
    for ( int j = 1 ; j < pbest.size() ; j++){
        if (resultados[j][0] > resultados[puntero][0]){
            puntero = j ;
        }
        else if ( resultados[j][0] == resultados[puntero][0] ){
            if ( resultados[j][1] < resultados[puntero][1] ){
                puntero = j ;
            }
        }
    }

    return puntero ;
}

int control::evaluateSolution(std::vector< std::vector< movimiento > > population){
    std::vector< std::vector< Coord > > posParticulas;
    std::vector<double> aux ;
    int puntero = 0 ;
    std::vector< std::vector<double> > resultadosAux ;


    posParticulas = getPosParticulas(population) ;

    for (int i = 0 ; i < posParticulas.size() ; i++ ){
        aux.push_back(o1(posParticulas[i])) ;
        aux.push_back(o32(posParticulas[i])) ;
        resultadosAux.push_back(aux) ;
        aux.clear();
    }
    for ( int k  = 0 ; k < resultados.size() ; k++){
        if (resultadosAux[k][0] > resultados[k][0]){
            pbest[k] = particulas[k];
        }
        else if ( resultadosAux[k][0] == resultados[k][0] ){
            if ( resultadosAux[k][1] < resultados[k][1] ){
                pbest[k] =particulas[k];
            }
        }
    }
    for ( int j = 1 ; j < resultados.size() ; j++){
        if (resultados[j][0] > resultados[puntero][0]){
            puntero = j ;
        }
        else if ( resultados[j][0] == resultados[puntero][0] ){
            if ( resultados[j][1] < resultados[puntero][1] ){
                puntero = j ;
            }
        }
    }

    return puntero ;
}

//-----ALGORITMO PRINCIPAL PSO-----//
std::vector<control::movimiento> control::pso(){
    int iteraciones = 0 ;
    int gb ;
    double phi2 = 0.5 ;
    double phi1 = 0.1 ;
    double w = 1.5 ;
    double Avij,Arij ;
    double r11,r12,r21,r22 ;
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> rand(0,1);

    //Inicializamos las Particulas
    initParticulas();
    //Evaluamos la Poblacion de Particulas Generadas
    gb = evaluatePopulation(particulas);
    EV << " YA TENEMOS UN GBEST = PARTICULA " << gb << "--------------------------\n" ;
    //Generamos una variable para almacenar la gbest en cada Iteracion
    std::vector<movimiento> gbest ;

    //Comienzan las iteraciones del Algoritmo PSO
    while(iteraciones < iteMax){
        w = w*0.98 ;

        gbest = pbest[gb] ;
        //EV<< "--------------------------------------\n" ;
        for( int i  = 0 ; i < particulas.size() ; i++){

            r11 = rand(generator);
            r12 = rand(generator);
            r21 = rand(generator);
            r22 = rand(generator);

            for ( int j = 0 ; j < numAgentes ; j++){
                Avij = (w*incrementos[i][j].modulo) + r11*phi1*(pbest[i][j].modulo - particulas[i][j].modulo) + r21*phi2*(gbest[j].modulo -particulas[i][j].modulo) ;
                Arij = (w*incrementos[i][j].angulo) + r12*phi1*(pbest[i][j].angulo - particulas[i][j].angulo) + r22*phi2*(gbest[j].modulo -particulas[i][j].modulo) ;
                incrementos[i][j].modulo = Avij ;
                incrementos[i][j].angulo = Arij ;
            }

            for ( int x = 0 ; x < incrementos[i].size() ; x++){
                if ( abs(incrementos[i][x].modulo) > maxSpeed ) {
                    incrementos[i][x].modulo /= (abs(incrementos[i][x].modulo) / maxSpeed);
                }
                if ( incrementos[i][x].angulo > 2*M_PI){
                    incrementos[i][x].angulo = incrementos[i][x].angulo - ( floor(incrementos[i][x].angulo / ( 2*M_PI )) * 2*M_PI ) ;
                }
                if ( incrementos[i][x].angulo < -2*M_PI){
                    incrementos[i][x].angulo = incrementos[i][x].angulo - ( ceil(incrementos[i][x].angulo / ( 2*M_PI )) * 2*M_PI ) ;
                }
            }

            for (int k = 0 ; k < numAgentes ; k++ ){
                particulas[i][k].modulo += incrementos[i][k].modulo ;
                particulas[i][k].angulo += incrementos[i][k].angulo ;
            }

            gb = evaluateSolution(particulas) ;

        }
        iteraciones++ ;
    }

    for ( int z = 0 ; z < particulas[gb].size() ; z ++) {
        if (particulas[gb][z].modulo > maxSpeed) particulas[gb][z].modulo = maxSpeed ;
        if (particulas[gb][z].modulo < -maxSpeed) particulas[gb][z].modulo = -maxSpeed ;
    }

    return particulas[gb] ;
}

//-----FUNCIONES UTILIZADAS PARA EVALUAR EL ESTADO DE LA RED Y RECOGER ESTADISTICAS-----//
double control::evaluateRed(bool agentes){
    std::vector<Coord> posiciones ;
    double conectividad ;

    posiciones.clear() ;
    if (agentes){
        for (int i = 0 ; i < numAgentes ; i++) posiciones.push_back(listaAgentes[i]->getCurrentPosition()) ;
        particionesNodos(posiciones) ;
        for ( int j = 0 ; j < posiciones.size();j++) EV << posiciones[j].x << " " << posiciones[j].y << "\n";
        conectividad = o1Red(listaParticionesN) ;
        EV << "particiones con Agente : \n" ;
        for (int k = 0 ; k < listaParticionesN.size() ; k++){
            for ( int x=0 ; x < listaParticionesN[k].size() ; x++){
                EV << listaParticionesN[k][x] << " " ;
            }
            EV << "\n" ;
        }
    } else{
        conectividad = o1Red(listaParticionesU) ;
    }

    return conectividad ;

}

void control::particionesNodos(std::vector<Coord> pos){
    std::vector<int> agenteConecta ;
    std::vector< std::vector< int > > part ;

    conectados2.clear();
    visitados2.clear();
    lista2.clear();
    conectados2 = conectados1 ;
    listaParticionesN.clear();


    for ( int z = 0 ; z < numUsuarios ; z++) visitados2.push_back(false) ;

    for ( int i = 0 ; i < pos.size() ; i++ ){
        for ( int j = 0 ; j < listaParticionesU.size() ; j++){
            for (int k = 0 ; k < listaParticionesU[j].size(); k++){
                if ( pos[i].distance(posUsuarios[listaParticionesU[j][k]]) <= distanciaCobertura){
                    agenteConecta.push_back(k) ;
                }
            }
        }
        for ( int x = 0 ; x < agenteConecta.size() ; x++ ){
            for ( int y = 0 ; y < agenteConecta.size() ; y++){
                if (x != y) conectados2[agenteConecta[x]][agenteConecta[y]] = true ;
            }
        }
        agenteConecta.clear() ;
    }

    for (int k = 0 ; k < numUsuarios ; k++ ){
        if (!visitados2[k]){
            dfs2(k) ;
            listaParticionesN.push_back(lista2) ;
            lista2.clear() ;
        }
    }

}

double control::o1Red(std::vector< std::vector< int > > lpn){
    double suma = 0 ;
    double resultado = 0 ;

    EV << "El tamano de LPN es : " << lpn.size() << "\n";
    for ( int i = 0 ; i < lpn.size() ; i++){
        suma += (lpn[i].size() - 1) * lpn[i].size() ;
    }
    resultado = suma /(numUsuarios*(numUsuarios-1)) ;

    return resultado ;

}

control::control(){
}

control::~control(){
}

