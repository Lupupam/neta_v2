package nesg.netattacks.detection.controllers.droppingDetectorDistributed;
import nesg.netattacks.detection.controllers.NA_Detector;

simple NA_droppingDetectorDistributed extends NA_Detector{
    parameters:
        @class(NA_DroppingDetectorDistributed);
        detectorType = "droppingD"; 		//Should correspond with the tag located in the hackedModules.ned.
        int eventWindowSize = default(100); //Size of the detection's event-based window.
        double threshold = default(0.15);	//Threshold for comparing the drop probability.
        int legitimatePeriodT @unit("s") = default(60s);	//Duration of the legitimate period T
        
        //Signals: Drop probabilty
        @signal[probDrop](type=long);
        @statistic[probDrop](title="Drop Probability"; record=count,vector; interpolationmode=none);
}
