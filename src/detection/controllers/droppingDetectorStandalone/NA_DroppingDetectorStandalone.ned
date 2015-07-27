package nesg.netattacks.detection.controllers.droppingDetectorStandalone;
import nesg.netattacks.detection.controllers.NA_Detector;

simple NA_DroppingDetectorStandalone extends NA_Detector{
    parameters:
        @class(NA_DroppingDetectorStandalone);
        detectorType = "droppingSA"; 		//Should correspond with the tag located in the hackedModules.ned.
        int eventWindowSize = default(100); //Size of the detection's event-based window.
        double threshold = default(0.15);	//Threshold for comparing the drop probability.
        int legitimatePeriodT @unit("s") = default(60s);	//Duration of the legitimate period T
        
        //Signals: Drop probabilty
        @signal[probDrop](type=long);
        @statistic[probDrop](title="Drop Probability"; record=count,vector; interpolationmode=none);
        @detector;

}
