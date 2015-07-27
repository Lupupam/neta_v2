#ifndef MOBILITYAGENTE_MOBILITY_H
#define MOBILITYAGENTE_MOBILITY_H

#include "INETDefs.h"

#include "LineSegmentsMobilityBase.h"


/**
 * @brief Models the mobility of with mass, making random motions.
 * See NED file for more info.
 *
 * @ingroup mobility
 * @author Emin Ilker Cetinbas, Andras Varga
 */
class INET_API mobilityAgente : public LineSegmentsMobilityBase
{
  protected:
    /** @brief Initializes mobility model parameters. */
    virtual void initialize(int stage);

    /** @brief Calculate a new target position to move to. */
    virtual void setTargetPosition();

  public:
    mobilityAgente();

    void moverA(double mod, double ang);

    double angle;
    double module;
    double maxSpeed;
    simtime_t updateInterval ;
};

#endif
