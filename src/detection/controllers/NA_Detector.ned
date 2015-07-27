package nesg.netattacks.detection.controllers;

simple NA_Detector
{
    parameters:
        @display("i=misc/cloud,green,100;is=l");
        string detectorType @enum("droppingSA","droppingDist") = default("");  //String with the type of detection
        bool active = default(false); 				//Indicates if this detection is active or not in the node
        double startTime @unit("s") = default(0s); 	// Timestamp to start the detection
        double endTime @unit("s") = default(0s); 	//Time instant at which the detection ends, 0 means that the detection will not end during the simulation.

        //Signals: Detection decision
        @signal[detectionResult](type=boolean);
        @statistic[detectionResult](title="Detection Results"; record=count,vector; interpolationmode=none);
        
        @signal[onceDetected](type=boolean);
        @statistic[onceDetected](title="Positive Detection"; record=count; interpolationmode=none);
}
