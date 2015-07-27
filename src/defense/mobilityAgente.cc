#include "mobilityAgente.h"
#include "FWMath.h"


Define_Module(mobilityAgente);


mobilityAgente::mobilityAgente()
{
    angle = 0;
    module = 0;
    maxSpeed = 0;
}

void mobilityAgente::initialize(int stage)
{
    LineSegmentsMobilityBase::initialize(stage);
    if (stage == 0)
    {
        angle = 0;
        module = par("Module").doubleValue() ;
        maxSpeed = par("MaxSpeed").doubleValue();
        updateInterval = par("updateInterval").doubleValue();
    }
}

void mobilityAgente::setTargetPosition()
{
    double x ,y ;
    if (module <= maxSpeed){
        x = module * cos(angle) ;
        y = module * sin(angle) ;
    } else{
        x = maxSpeed * cos(angle) ;
        y = maxSpeed * sin(angle) ;
    }
    targetPosition.x = lastPosition.x + x ;
    targetPosition.y = lastPosition.y + y ;
    targetPosition.z = lastPosition.z + 0 ;
    nextChange = simTime() + updateInterval;
}

void mobilityAgente::moverA(double mod, double ang){
    module = mod ;
    angle = ang ;
    EV << "MODULO : " << module << "\nANGULO : " << angle <<"\n" ;
}

