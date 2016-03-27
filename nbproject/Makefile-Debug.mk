#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/JSONParser.o \
	${OBJECTDIR}/MessageHandler.o \
	${OBJECTDIR}/SimulationManager.o \
	${OBJECTDIR}/SocketClient.o \
	${OBJECTDIR}/SocketServer.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/MessageHandlerTest.o \
	${TESTDIR}/tests/MessageHandlerTestRunner.o \
	${TESTDIR}/tests/SocketCommunicationTest.o \
	${TESTDIR}/tests/SocketCommunicationTestRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lzmq -lpthread
CXXFLAGS=-lzmq -lpthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a

${OBJECTDIR}/JSONParser.o: JSONParser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JSONParser.o JSONParser.cpp

${OBJECTDIR}/MessageHandler.o: MessageHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MessageHandler.o MessageHandler.cpp

${OBJECTDIR}/SimulationManager.o: SimulationManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SimulationManager.o SimulationManager.cpp

${OBJECTDIR}/SocketClient.o: SocketClient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketClient.o SocketClient.cpp

${OBJECTDIR}/SocketServer.o: SocketServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketServer.o SocketServer.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd /mnt/seagate_1TB/Development/Robotkar_reboot/RoboticArmPartLibrary && ${MAKE}  -f Makefile CONF=Debug
	cd /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/MessageHandlerTest.o ${TESTDIR}/tests/MessageHandlerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -lzmq  -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/dist/Debug/GNU-Linux/libpartcontainerlibrary.a /mnt/seagate_1TB/Development/Robotkar_reboot/RoboticArmPartLibrary/dist/Debug/GNU-Linux/libroboticarmpartlibrary.a /mnt/western_digital_2TB/Development/Robotkar/CustomLibraries/libjson.a `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/SocketCommunicationTest.o ${TESTDIR}/tests/SocketCommunicationTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -lzmq  -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} /mnt/seagate_1TB/Development/Robotkar_reboot/PartContainerLibrary/dist/Debug/GNU-Linux/libpartcontainerlibrary.a /mnt/seagate_1TB/Development/Robotkar_reboot/RoboticArmPartLibrary/dist/Debug/GNU-Linux/libroboticarmpartlibrary.a /mnt/western_digital_2TB/Development/Robotkar/CustomLibraries/libjson.a `cppunit-config --libs`   


${TESTDIR}/tests/MessageHandlerTest.o: tests/MessageHandlerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MessageHandlerTest.o tests/MessageHandlerTest.cpp


${TESTDIR}/tests/MessageHandlerTestRunner.o: tests/MessageHandlerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MessageHandlerTestRunner.o tests/MessageHandlerTestRunner.cpp


${TESTDIR}/tests/SocketCommunicationTest.o: tests/SocketCommunicationTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/SocketCommunicationTest.o tests/SocketCommunicationTest.cpp


${TESTDIR}/tests/SocketCommunicationTestRunner.o: tests/SocketCommunicationTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/SocketCommunicationTestRunner.o tests/SocketCommunicationTestRunner.cpp


${OBJECTDIR}/JSONParser_nomain.o: ${OBJECTDIR}/JSONParser.o JSONParser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/JSONParser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JSONParser_nomain.o JSONParser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/JSONParser.o ${OBJECTDIR}/JSONParser_nomain.o;\
	fi

${OBJECTDIR}/MessageHandler_nomain.o: ${OBJECTDIR}/MessageHandler.o MessageHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MessageHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MessageHandler_nomain.o MessageHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MessageHandler.o ${OBJECTDIR}/MessageHandler_nomain.o;\
	fi

${OBJECTDIR}/SimulationManager_nomain.o: ${OBJECTDIR}/SimulationManager.o SimulationManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SimulationManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SimulationManager_nomain.o SimulationManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SimulationManager.o ${OBJECTDIR}/SimulationManager_nomain.o;\
	fi

${OBJECTDIR}/SocketClient_nomain.o: ${OBJECTDIR}/SocketClient.o SocketClient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SocketClient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketClient_nomain.o SocketClient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SocketClient.o ${OBJECTDIR}/SocketClient_nomain.o;\
	fi

${OBJECTDIR}/SocketServer_nomain.o: ${OBJECTDIR}/SocketServer.o SocketServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SocketServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -include /mnt/seagate_1TB/Development/Robotkar_reboot/CustomLibraries/json.hh -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketServer_nomain.o SocketServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SocketServer.o ${OBJECTDIR}/SocketServer_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocketserver.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
