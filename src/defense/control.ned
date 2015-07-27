package nesg.netattacks.defense;

simple control
{
    @class("control");
    @display("i=old/bwsink,red");
    volatile double updateInterval @unit(s)  ;
    volatile double MaxSpeed @unit(mps); // speed
    volatile int Nparticulas ;
    volatile int iterMax ;
    @control; //Etiqueta para identificacion
    
    //PARA EL PATHLOSS Y LA CONEXION DE NODOS//
    volatile double carrierFreq @unit(GHz) ; // Frecuencia de la portadora
    volatile double potenciaMax @unit(mW) ; // Potencia M�xima
    volatile double alpha ; // Alpha
    volatile double sensibilidad @unit(dBm ) ; 
   	
}
