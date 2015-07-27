//
// Copyright (C) 2013 by NESG (Network Engineering and Security Group), http://nesg.ugr.es
// Dept. of Signal Theory, Telematics and Communications
// University of Granada
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//


//
// Message interchanged between dropping detection controller and the corresponding hacked
// modules. 
//

message NA_DroppingDetectorStandaloneMessage {
    long SentRTS;
    long ReceivedCTS;
    long pMob;
    long FordwardedCount;
    long ReceivedCount;
    long RREQCount;
    long EventWindowSize;
}