#
# OMNeT++/OMNEST Makefile for netattacks_v2
#
# This file was generated with the command:
#  opp_makemake -f --deep -I../../inet25/src/world/radio -I../../inet25/src/linklayer/common -I../../inet25/src/applications/pingapp -I../../inet25/src/networklayer/routing/aodv -I../../inet25/src/networklayer/icmpv6 -I../../inet25/src/linklayer/radio -I../../inet25/src/transport/sctp -I../../inet25/src/util/headerserializers/ipv6 -I../../inet25/src/networklayer/ipv6 -I../../inet25/src/networklayer/autorouting/ipv4 -I../../inet25/src/util/headerserializers/sctp -I../../inet25/src/linklayer/contract -I../../inet25/src/linklayer/ieee80211/mac -I../../inet25/src/battery/models -I../../inet25/src/networklayer/ipv4 -I../../inet25/src/linklayer/radio/propagation -I../../inet25/src/transport/tcp_common -I../../inet25/src/util -I../../inet25/src/linklayer/ieee80211/radio -I../../inet25/src/util/headerserializers/tcp -I../../inet25/src/networklayer/xmipv6 -I../../inet25/src -I../../inet25/src/mobility/contract -I../../inet25/src/networklayer/contract -I../../inet25/src/transport/contract -I../../inet25/src/status -I../../inet25/src/util/headerserializers/udp -I../../inet25/src/world/obstacles -I../../inet25/src/transport/udp -I../../inet25/src/util/headerserializers/ipv4 -I../../inet25/src/base -I../../inet25/src/linklayer/ieee80211/radio/errormodel -I../../inet25/src/networklayer/ipv6tunneling -I../../inet25/src/networklayer/common -I../../inet25/src/networklayer/arp -I../../inet25/src/util/headerserializers -I../../inet25/src/applications/udpapp -I../../inet25/src/applications/common -I../../inet25/src/mobility/common -I../../inet25/src/networklayer/manetrouting/base -I../../inet25/src/networklayer/manetrouting/dsr -I../../inet25/src/linklayer/ieee80211/mgmt -I../../inet25/src/linklayer/ethernet -L../../inet25/out/$$\(CONFIGNAME\)/src -linet -DWITH_TCP_COMMON -DWITH_TCP_INET -DWITH_IPv4 -DWITH_IPv6 -DWITH_xMIPv6 -DWITH_UDP -DWITH_RTP -DWITH_SCTP -DWITH_ETHERNET -DWITH_PPP -DWITH_EXT_IF -DWITH_MPLS -DWITH_OSPFv2 -DWITH_BGPv4 -DWITH_MANET -DWITH_DHCP -DINET_IMPORT -KINET25_PROJ=../../inet25
#

# Name of target to be created (-o option)
TARGET = netattacks_v2$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet25/src/world/radio \
    -I../../inet25/src/linklayer/common \
    -I../../inet25/src/applications/pingapp \
    -I../../inet25/src/networklayer/routing/aodv \
    -I../../inet25/src/networklayer/icmpv6 \
    -I../../inet25/src/linklayer/radio \
    -I../../inet25/src/transport/sctp \
    -I../../inet25/src/util/headerserializers/ipv6 \
    -I../../inet25/src/networklayer/ipv6 \
    -I../../inet25/src/networklayer/autorouting/ipv4 \
    -I../../inet25/src/util/headerserializers/sctp \
    -I../../inet25/src/linklayer/contract \
    -I../../inet25/src/linklayer/ieee80211/mac \
    -I../../inet25/src/battery/models \
    -I../../inet25/src/networklayer/ipv4 \
    -I../../inet25/src/linklayer/radio/propagation \
    -I../../inet25/src/transport/tcp_common \
    -I../../inet25/src/util \
    -I../../inet25/src/linklayer/ieee80211/radio \
    -I../../inet25/src/util/headerserializers/tcp \
    -I../../inet25/src/networklayer/xmipv6 \
    -I../../inet25/src \
    -I../../inet25/src/mobility/contract \
    -I../../inet25/src/networklayer/contract \
    -I../../inet25/src/transport/contract \
    -I../../inet25/src/status \
    -I../../inet25/src/util/headerserializers/udp \
    -I../../inet25/src/world/obstacles \
    -I../../inet25/src/transport/udp \
    -I../../inet25/src/util/headerserializers/ipv4 \
    -I../../inet25/src/base \
    -I../../inet25/src/linklayer/ieee80211/radio/errormodel \
    -I../../inet25/src/networklayer/ipv6tunneling \
    -I../../inet25/src/networklayer/common \
    -I../../inet25/src/networklayer/arp \
    -I../../inet25/src/util/headerserializers \
    -I../../inet25/src/applications/udpapp \
    -I../../inet25/src/applications/common \
    -I../../inet25/src/mobility/common \
    -I../../inet25/src/networklayer/manetrouting/base \
    -I../../inet25/src/networklayer/manetrouting/dsr \
    -I../../inet25/src/linklayer/ieee80211/mgmt \
    -I../../inet25/src/linklayer/ethernet \
    -I. \
    -Iadaptation \
    -Iadaptation/notification \
    -Iadaptation/respuesta \
    -Iattacks \
    -Iattacks/controllers \
    -Iattacks/controllers/delayAttack \
    -Iattacks/controllers/droppingAttack \
    -Iattacks/controllers/sinkholeAttack \
    -Iattacks/controlmessages \
    -Iattacks/controlmessages/delayAttack \
    -Iattacks/controlmessages/droppingAttack \
    -Iattacks/controlmessages/sinkholeAttack \
    -Icommon \
    -Icommon/log \
    -Icommon/utils \
    -Idefense \
    -Idetection \
    -Idetection/controllers \
    -Idetection/controllers/droppingDetectorDistributed \
    -Idetection/controllers/droppingDetectorStandalone \
    -Idetection/controlmessages \
    -Idetection/controlmessages/droppingDetectorDistributed \
    -Idetection/controlmessages/droppingDetectorStandalone \
    -Ihackedmodules \
    -Ihackedmodules/applications \
    -Ihackedmodules/applications/udpapp \
    -Ihackedmodules/linklayer \
    -Ihackedmodules/linklayer/ieee80211 \
    -Ihackedmodules/linklayer/ieee80211/mac \
    -Ihackedmodules/networklayer \
    -Ihackedmodules/networklayer/ipv4 \
    -Ihackedmodules/networklayer/manetrouting \
    -Ihackedmodules/networklayer/manetrouting/aodv \
    -Ihackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu \
    -Inodes \
    -Inotification \
    -Inotification/controllers \
    -Inotification/controlmessages \
    -Inotification/defense \
    -Inotification/defense/basic

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inet25/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath ../../inet25/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/adaptation/notification/NA_ModuleAdapter.o \
    $O/adaptation/respuesta/NA_DefenseAdapter.o \
    $O/attacks/controllers/NA_Attack.o \
    $O/attacks/controllers/delayAttack/NA_DelayAttack.o \
    $O/attacks/controllers/droppingAttack/NA_DroppingAttack.o \
    $O/attacks/controllers/sinkholeAttack/NA_SinkholeAttack.o \
    $O/common/log/NA_NesgLog.o \
    $O/common/utils/NA_Utils.o \
    $O/defense/mobilityAgente.o \
    $O/defense/control.o \
    $O/detection/controllers/NA_Detector.o \
    $O/detection/controllers/droppingDetectorDistributed/NA_DroppingDetectorDistributed.o \
    $O/detection/controllers/droppingDetectorStandalone/NA_DroppingDetectorStandalone.o \
    $O/hackedmodules/NA_HackedModule.o \
    $O/hackedmodules/applications/udpapp/NA_UDPBasicBurst.o \
    $O/hackedmodules/linklayer/ieee80211/mac/NA_Ieee80211Mac.o \
    $O/hackedmodules/networklayer/ipv4/NA_IPv4.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.o \
    $O/notification/NA_Notification_omnet.o \
    $O/notification/controllers/NA_Notification_Controller.o \
    $O/notification/defense/NA_Notification_Module.o \
    $O/notification/defense/basic/Defense_Basic.o \
    $O/attacks/controlmessages/delayAttack/NA_DelayMessage_m.o \
    $O/attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.o \
    $O/attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.o \
    $O/detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.o \
    $O/detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.o \
    $O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.o \
    $O/notification/controlmessages/NA_notification_msg_struct_m.o

# Message files
MSGFILES = \
    attacks/controlmessages/delayAttack/NA_DelayMessage.msg \
    attacks/controlmessages/droppingAttack/NA_DroppingMessage.msg \
    attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage.msg \
    detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage.msg \
    detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage.msg \
    hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.msg \
    notification/controlmessages/NA_notification_msg_struct.msg

# Other makefile variables (-K)
INET25_PROJ=../../inet25

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) \
    -DWITH_TCP_COMMON \
    -DWITH_TCP_INET \
    -DWITH_IPv4 \
    -DWITH_IPv6 \
    -DWITH_xMIPv6 \
    -DWITH_UDP \
    -DWITH_RTP \
    -DWITH_SCTP \
    -DWITH_ETHERNET \
    -DWITH_PPP \
    -DWITH_EXT_IF \
    -DWITH_MPLS \
    -DWITH_OSPFv2 \
    -DWITH_BGPv4 \
    -DWITH_MANET \
    -DWITH_DHCP \
    -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f netattacks_v2 netattacks_v2.exe libnetattacks_v2.so libnetattacks_v2.a libnetattacks_v2.dll libnetattacks_v2.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f adaptation/*_m.cc adaptation/*_m.h
	$(Q)-rm -f adaptation/notification/*_m.cc adaptation/notification/*_m.h
	$(Q)-rm -f adaptation/respuesta/*_m.cc adaptation/respuesta/*_m.h
	$(Q)-rm -f attacks/*_m.cc attacks/*_m.h
	$(Q)-rm -f attacks/controllers/*_m.cc attacks/controllers/*_m.h
	$(Q)-rm -f attacks/controllers/delayAttack/*_m.cc attacks/controllers/delayAttack/*_m.h
	$(Q)-rm -f attacks/controllers/droppingAttack/*_m.cc attacks/controllers/droppingAttack/*_m.h
	$(Q)-rm -f attacks/controllers/sinkholeAttack/*_m.cc attacks/controllers/sinkholeAttack/*_m.h
	$(Q)-rm -f attacks/controlmessages/*_m.cc attacks/controlmessages/*_m.h
	$(Q)-rm -f attacks/controlmessages/delayAttack/*_m.cc attacks/controlmessages/delayAttack/*_m.h
	$(Q)-rm -f attacks/controlmessages/droppingAttack/*_m.cc attacks/controlmessages/droppingAttack/*_m.h
	$(Q)-rm -f attacks/controlmessages/sinkholeAttack/*_m.cc attacks/controlmessages/sinkholeAttack/*_m.h
	$(Q)-rm -f common/*_m.cc common/*_m.h
	$(Q)-rm -f common/log/*_m.cc common/log/*_m.h
	$(Q)-rm -f common/utils/*_m.cc common/utils/*_m.h
	$(Q)-rm -f defense/*_m.cc defense/*_m.h
	$(Q)-rm -f detection/*_m.cc detection/*_m.h
	$(Q)-rm -f detection/controllers/*_m.cc detection/controllers/*_m.h
	$(Q)-rm -f detection/controllers/droppingDetectorDistributed/*_m.cc detection/controllers/droppingDetectorDistributed/*_m.h
	$(Q)-rm -f detection/controllers/droppingDetectorStandalone/*_m.cc detection/controllers/droppingDetectorStandalone/*_m.h
	$(Q)-rm -f detection/controlmessages/*_m.cc detection/controlmessages/*_m.h
	$(Q)-rm -f detection/controlmessages/droppingDetectorDistributed/*_m.cc detection/controlmessages/droppingDetectorDistributed/*_m.h
	$(Q)-rm -f detection/controlmessages/droppingDetectorStandalone/*_m.cc detection/controlmessages/droppingDetectorStandalone/*_m.h
	$(Q)-rm -f hackedmodules/*_m.cc hackedmodules/*_m.h
	$(Q)-rm -f hackedmodules/applications/*_m.cc hackedmodules/applications/*_m.h
	$(Q)-rm -f hackedmodules/applications/udpapp/*_m.cc hackedmodules/applications/udpapp/*_m.h
	$(Q)-rm -f hackedmodules/linklayer/*_m.cc hackedmodules/linklayer/*_m.h
	$(Q)-rm -f hackedmodules/linklayer/ieee80211/*_m.cc hackedmodules/linklayer/ieee80211/*_m.h
	$(Q)-rm -f hackedmodules/linklayer/ieee80211/mac/*_m.cc hackedmodules/linklayer/ieee80211/mac/*_m.h
	$(Q)-rm -f hackedmodules/networklayer/*_m.cc hackedmodules/networklayer/*_m.h
	$(Q)-rm -f hackedmodules/networklayer/ipv4/*_m.cc hackedmodules/networklayer/ipv4/*_m.h
	$(Q)-rm -f hackedmodules/networklayer/manetrouting/*_m.cc hackedmodules/networklayer/manetrouting/*_m.h
	$(Q)-rm -f hackedmodules/networklayer/manetrouting/aodv/*_m.cc hackedmodules/networklayer/manetrouting/aodv/*_m.h
	$(Q)-rm -f hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/*_m.cc hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/*_m.h
	$(Q)-rm -f nodes/*_m.cc nodes/*_m.h
	$(Q)-rm -f notification/*_m.cc notification/*_m.h
	$(Q)-rm -f notification/controllers/*_m.cc notification/controllers/*_m.h
	$(Q)-rm -f notification/controlmessages/*_m.cc notification/controlmessages/*_m.h
	$(Q)-rm -f notification/defense/*_m.cc notification/defense/*_m.h
	$(Q)-rm -f notification/defense/basic/*_m.cc notification/defense/basic/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc adaptation/*.cc adaptation/notification/*.cc adaptation/respuesta/*.cc attacks/*.cc attacks/controllers/*.cc attacks/controllers/delayAttack/*.cc attacks/controllers/droppingAttack/*.cc attacks/controllers/sinkholeAttack/*.cc attacks/controlmessages/*.cc attacks/controlmessages/delayAttack/*.cc attacks/controlmessages/droppingAttack/*.cc attacks/controlmessages/sinkholeAttack/*.cc common/*.cc common/log/*.cc common/utils/*.cc defense/*.cc detection/*.cc detection/controllers/*.cc detection/controllers/droppingDetectorDistributed/*.cc detection/controllers/droppingDetectorStandalone/*.cc detection/controlmessages/*.cc detection/controlmessages/droppingDetectorDistributed/*.cc detection/controlmessages/droppingDetectorStandalone/*.cc hackedmodules/*.cc hackedmodules/applications/*.cc hackedmodules/applications/udpapp/*.cc hackedmodules/linklayer/*.cc hackedmodules/linklayer/ieee80211/*.cc hackedmodules/linklayer/ieee80211/mac/*.cc hackedmodules/networklayer/*.cc hackedmodules/networklayer/ipv4/*.cc hackedmodules/networklayer/manetrouting/*.cc hackedmodules/networklayer/manetrouting/aodv/*.cc hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/*.cc nodes/*.cc notification/*.cc notification/controllers/*.cc notification/controlmessages/*.cc notification/defense/*.cc notification/defense/basic/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/adaptation/notification/NA_ModuleAdapter.o: adaptation/notification/NA_ModuleAdapter.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET25_PROJ)/src/mobility/contract/IMobility.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	adaptation/notification/NA_ModuleAdapter.h \
	defense/control.h \
	defense/mobilityAgente.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/adaptation/respuesta/NA_DefenseAdapter.o: adaptation/respuesta/NA_DefenseAdapter.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/IScriptable.h \
	$(INET25_PROJ)/src/base/LifecycleController.h \
	$(INET25_PROJ)/src/base/LifecycleOperation.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NodeOperations.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET25_PROJ)/src/mobility/contract/IMobility.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/status/NodeStatus.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	adaptation/respuesta/NA_DefenseAdapter.h \
	defense/control.h \
	defense/mobilityAgente.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/attacks/controllers/NA_Attack.o: attacks/controllers/NA_Attack.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	attacks/controllers/NA_Attack.h \
	attacks/controlmessages/delayAttack/NA_DelayMessage_m.h \
	attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/ipv4/NA_IPv4.h
$O/attacks/controllers/delayAttack/NA_DelayAttack.o: attacks/controllers/delayAttack/NA_DelayAttack.cc \
	attacks/controllers/NA_Attack.h \
	attacks/controllers/delayAttack/NA_DelayAttack.h \
	attacks/controlmessages/delayAttack/NA_DelayMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h
$O/attacks/controllers/droppingAttack/NA_DroppingAttack.o: attacks/controllers/droppingAttack/NA_DroppingAttack.cc \
	attacks/controllers/NA_Attack.h \
	attacks/controllers/droppingAttack/NA_DroppingAttack.h \
	attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h
$O/attacks/controllers/sinkholeAttack/NA_SinkholeAttack.o: attacks/controllers/sinkholeAttack/NA_SinkholeAttack.cc \
	attacks/controllers/NA_Attack.h \
	attacks/controllers/sinkholeAttack/NA_SinkholeAttack.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h
$O/attacks/controlmessages/delayAttack/NA_DelayMessage_m.o: attacks/controlmessages/delayAttack/NA_DelayMessage_m.cc \
	attacks/controlmessages/delayAttack/NA_DelayMessage_m.h
$O/attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.o: attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.cc \
	attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.h
$O/attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.o: attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.cc \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h
$O/common/log/NA_NesgLog.o: common/log/NA_NesgLog.cc \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h
$O/common/utils/NA_Utils.o: common/utils/NA_Utils.cc \
	common/utils/NA_Utils.h
$O/defense/control.o: defense/control.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET25_PROJ)/src/mobility/contract/IMobility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	$(INET25_PROJ)/src/world/radio/ChannelControl.h \
	$(INET25_PROJ)/src/world/radio/IChannelControl.h \
	defense/control.h \
	defense/mobilityAgente.h
$O/defense/mobilityAgente.o: defense/mobilityAgente.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET25_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET25_PROJ)/src/mobility/contract/IMobility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	defense/mobilityAgente.h
$O/detection/controllers/NA_Detector.o: detection/controllers/NA_Detector.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	attacks/controlmessages/delayAttack/NA_DelayMessage_m.h \
	attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/ipv4/NA_IPv4.h
$O/detection/controllers/droppingDetectorDistributed/NA_DroppingDetectorDistributed.o: detection/controllers/droppingDetectorDistributed/NA_DroppingDetectorDistributed.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	adaptation/notification/NA_ModuleAdapter.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controllers/droppingDetectorDistributed/NA_DroppingDetectorDistributed.h \
	detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/detection/controllers/droppingDetectorStandalone/NA_DroppingDetectorStandalone.o: detection/controllers/droppingDetectorStandalone/NA_DroppingDetectorStandalone.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	adaptation/notification/NA_ModuleAdapter.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controllers/droppingDetectorStandalone/NA_DroppingDetectorStandalone.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.o: detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.cc \
	detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.h
$O/detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.o: detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.cc \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h
$O/hackedmodules/NA_HackedModule.o: hackedmodules/NA_HackedModule.cc \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	hackedmodules/NA_HackedModule.h
$O/hackedmodules/applications/udpapp/NA_UDPBasicBurst.o: hackedmodules/applications/udpapp/NA_UDPBasicBurst.cc \
	$(INET25_PROJ)/src/applications/common/ApplicationBase.h \
	$(INET25_PROJ)/src/applications/udpapp/UDPBasicBurst.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/LifecycleOperation.h \
	$(INET25_PROJ)/src/base/NodeOperations.h \
	$(INET25_PROJ)/src/base/OperationalBase.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET25_PROJ)/src/transport/contract/UDPSocket.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	hackedmodules/applications/udpapp/NA_UDPBasicBurst.h
$O/hackedmodules/linklayer/ieee80211/mac/NA_Ieee80211Mac.o: hackedmodules/linklayer/ieee80211/mac/NA_Ieee80211Mac.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/FSMA.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/IPassiveQueue.h \
	$(INET25_PROJ)/src/base/LifecycleOperation.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NodeOperations.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/common/MACBase.h \
	$(INET25_PROJ)/src/linklayer/common/WirelessMacBase.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/contract/PhyControlInfo_m.h \
	$(INET25_PROJ)/src/linklayer/contract/RadioState.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/IQoSClassifier.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211DataRate.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Mac.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211eClassifier.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/WifiMode.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/radio/WifiPreambleType.h \
	$(INET25_PROJ)/src/linklayer/radio/AirFrame_m.h \
	$(INET25_PROJ)/src/linklayer/radio/ModulationType.h \
	$(INET25_PROJ)/src/linklayer/radio/Radio80211aControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/status/NodeStatus.h \
	$(INET25_PROJ)/src/transport/contract/UDPControlInfo.h \
	$(INET25_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controllers/droppingDetectorStandalone/NA_DroppingDetectorStandalone.h \
	detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage_m.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/linklayer/ieee80211/mac/NA_Ieee80211Mac.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h
$O/hackedmodules/networklayer/ipv4/NA_IPv4.o: hackedmodules/networklayer/ipv4/NA_IPv4.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/LifecycleOperation.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NodeOperations.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/status/NodeStatus.h \
	attacks/controlmessages/delayAttack/NA_DelayMessage_m.h \
	attacks/controlmessages/droppingAttack/NA_DroppingMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/ipv4/NA_IPv4.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ControlManetRouting_m.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.o: hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.cc \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.o: hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.cc \
	$(INET25_PROJ)/src/base/AbstractQueue.h \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/Coord.h \
	$(INET25_PROJ)/src/base/ILifecycle.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/base/ProtocolMap.h \
	$(INET25_PROJ)/src/base/QueueBase.h \
	$(INET25_PROJ)/src/base/ReassemblyBuffer.h \
	$(INET25_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET25_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET25_PROJ)/src/networklayer/arp/ARP.h \
	$(INET25_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	$(INET25_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4FragBuf.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET25_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetAddress.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetNetfilterHook.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/ManetRoutingBase.h \
	$(INET25_PROJ)/src/networklayer/manetrouting/base/compatibility.h \
	$(INET25_PROJ)/src/util/FWMath.h \
	attacks/controlmessages/sinkholeAttack/NA_SinkholeMessage_m.h \
	common/log/NA_NesgLog.h \
	common/utils/NA_Utils.h \
	detection/controllers/NA_Detector.h \
	detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage_m.h \
	hackedmodules/NA_HackedModule.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_hello.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_neighbor.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rerr.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rrep.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_rreq.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_socket.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_aodv_timeout.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_debug_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_defs_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_locality.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_params.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_routing_table.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_seek_list.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv-uu/NA_timer_queue_aodv.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_msg_struct_m.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_aodv_uu_omnet.h \
	hackedmodules/networklayer/manetrouting/aodv/NA_packet_queue_omnet.h
$O/notification/NA_Notification_omnet.o: notification/NA_Notification_omnet.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/notification/controllers/NA_Notification_Controller.o: notification/controllers/NA_Notification_Controller.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/notification/controlmessages/NA_notification_msg_struct_m.o: notification/controlmessages/NA_notification_msg_struct_m.cc \
	notification/controlmessages/NA_notification_msg_struct_m.h
$O/notification/defense/NA_Notification_Module.o: notification/defense/NA_Notification_Module.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h
$O/notification/defense/basic/Defense_Basic.o: notification/defense/basic/Defense_Basic.cc \
	$(INET25_PROJ)/src/base/Compat.h \
	$(INET25_PROJ)/src/base/INETDefs.h \
	$(INET25_PROJ)/src/base/INotifiable.h \
	$(INET25_PROJ)/src/base/ModuleAccess.h \
	$(INET25_PROJ)/src/base/NotificationBoard.h \
	$(INET25_PROJ)/src/base/NotifierConsts.h \
	$(INET25_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET25_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET25_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET25_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET25_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET25_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET25_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET25_PROJ)/src/transport/udp/UDPPacket_m.h \
	notification/NA_Notification_omnet.h \
	notification/controllers/NA_Notification_Controller.h \
	notification/controlmessages/NA_notification_msg_struct_m.h \
	notification/defense/NA_Notification_Module.h \
	notification/defense/basic/Defense_Basic.h

