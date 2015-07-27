package nesg.netattacks.defense;

import inet.mobility.common.MovingMobilityBase ;

simple mobilityAgente extends MovingMobilityBase
{
    parameters:
        double initialX @unit(m) = default(uniform(constraintAreaMinX, constraintAreaMaxX));
        double initialY @unit(m) = default(uniform(constraintAreaMinY, constraintAreaMaxY));
        double initialZ @unit(m) = default(uniform(constraintAreaMinZ, constraintAreaMaxZ));
        double startAngle @unit(deg) = default(uniform(0deg, 360deg)); // initial angle in degrees
        bool initFromDisplayString = default(false);
        volatile double changeInterval @unit(s); // frequency of changing speed and angle (can be random)
        volatile double Module = default(0);
        volatile double MaxSpeed @unit(mps) = default(50mps); // speed (can be random, updated every changeInterval)
        double waitTime @unit(s) = default(1s) ;
        @class(mobilityAgente);
        @agente ;
}