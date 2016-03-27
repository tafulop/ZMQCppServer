/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MessageHandlerTest.cpp
 * Author: fulop
 *
 * Created on Mar 27, 2016, 1:40:32 PM
 */

#include "MessageHandlerTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(MessageHandlerTest);

MessageHandlerTest::MessageHandlerTest() {
}

MessageHandlerTest::~MessageHandlerTest() {
}

void MessageHandlerTest::setUp() {
}

void MessageHandlerTest::tearDown() {
}

void MessageHandlerTest::jointDataRead() {
    
    MessageHandler msgHandler = MessageHandler::getInstance();
    PartContainerManager partMgr = PartContainerManager::getInstance();
    
    // creating joint to read back its data
    RoboticArm::Joint j1 = RoboticArm::Joint("Joint 1", 1, 1);
    j1.setAngle(1234.5678);
    partMgr.joints.add("J1", j1);
    
    // read joint data
    
    
    
    CPPUNIT_ASSERT(true);
}


