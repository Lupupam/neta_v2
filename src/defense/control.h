#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <Coord.h>
#include "LineSegmentsMobilityBase.h"
#include "mobilityAgente.h"

#ifndef CONTROL_H_
#define CONTROL_H_

//Definimos la velocidad de la luz
#define V_LUZ 299792458.0

class control: public cSimpleModule {
public:
    virtual void initializeDefense();
    virtual void getNodosUsuario();
    bool activado;
    control();
    virtual ~control();
    simtime_t updateInterval;
    double maxSpeed, distanciaCobertura, fPortadora, potMaxTX, alpha, sensibilidad ; //saturacion
    int numUsuarios, numAgentes, Nparticulas,iteMax ;

    struct movimiento{
        double modulo ;
        double angulo ;
    };

private:
    //-----LISTAS DONDE SE RECOGEN LOS MODULOS DE MOBILIDAD DE LOS DISTITNOS TIPOS DE NODOS-----//
    std::vector<mobilityAgente *> listaAgentes;
    std::vector<LineSegmentsMobilityBase *> listaUsuarios;
    //----- UTILIZADOS PARA SECCIONES, POSICIONES INICIALES y PUNTOS DE ATRACCION----- //
    std::vector< std::vector< int > > listaParticionesU;
    std::vector< std::vector< int > > listaParticionesN;
    std::vector< std::vector< bool > > conectados1 ;
    std::vector< std::vector< bool > > conectados2 ;
    std::vector< int > lista2 ;
    std::vector< int > lista1 ;
    std::vector< bool > visitados1 ;
    std::vector< bool > visitados2 ;
    std::vector< Coord > pAtraccion ;
    std::vector< Coord > posUsuarios;
    //----- UTILIZADOS PARA INITPARTICULAS-----//
    std::vector< std::vector< movimiento > > particulas;
    std::vector< std::vector< movimiento > > incrementos;
    //-----UTILIZADOS PARA LAS FUNCIONES DE EVALUACION -----//
    std::vector< std::vector< movimiento > > pbest;
    std::vector< std::vector<double> > resultados;
    //----- SENALES PARA RECOLECTAR ESTADISTICAS -----//
    cLongHistogram ConectividadNoAgentesStats;
    cLongHistogram ConectividadSiAgentesStats;
    cOutVector ConectividadNoAgentes ;
    cOutVector ConectividadSiAgentes ;

protected:
    //----- INICIACION DEL ESCENARIO -----//
    virtual void initialize();
    virtual void getNodosAgente() ;

    virtual double calcDistCobertura(double f, double a, double s, double p) ;
    virtual void handleMessage(cMessage *msg);
    //----- SECCIONES, POSICIONES Y PUNTOS DE ATRACCION ----//
    virtual void particionesUsuarios() ;
    virtual std::vector< std::vector< int > >particiones(std::vector<Coord> posAgentes) ;
    virtual void dfs1( int puntero ) ;
    virtual void dfs2( int puntero ) ;
    virtual void getPA() ;
    //----- INICIACION DE PARTICULAS ----//
    virtual void initParticulas() ;
    virtual std::vector< std::vector<Coord> > getPosParticulas(std::vector< std::vector< movimiento > > p);
    //----- EVALUACION DE POPILACION -----//
    virtual int evaluatePopulation(std::vector< std::vector< movimiento > > population) ;
    virtual int evaluateSolution(std::vector< std::vector< movimiento > > population) ;
    //----- FUNCIONES DE OPTIMIZACION ----//
    virtual double o1(std::vector<Coord> pParticulas) ;
    virtual double o3(std::vector<Coord> pParticulas) ;
    virtual double o32(std::vector<Coord> pParticulas) ;
    //----- UTILIZADS PARA EVALUAR LA RED TRAS EL PSO CON O SIN AGENTES ----//
    virtual double evaluateRed(bool agentes) ;
    virtual double o1Red(std::vector< std::vector< int > > lpn ) ;
    virtual void particionesNodos(std::vector<Coord> pos) ;
    //-----FUNCION PRINCIPAL PSO -----//
    virtual std::vector<movimiento> pso() ;

};

#endif /* CONTROL_H_ */
