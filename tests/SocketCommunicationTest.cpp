/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SocketCommunicationTest.cpp
 * Author: fulop
 *
 * Created on Mar 15, 2016, 1:38:37 PM
 */

#include "SocketCommunicationTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(SocketCommunicationTest);

SocketCommunicationTest::SocketCommunicationTest() {
}

SocketCommunicationTest::~SocketCommunicationTest() {
}

void SocketCommunicationTest::setUp() {
}

void SocketCommunicationTest::tearDown() {
}

void SocketCommunicationTest::testMethod() {
    
    SocketServer::getInstance().runServer();
    
    std::thread client (SocketClient::JSONSendingTest);
    
    client.join();
    
    CPPUNIT_ASSERT(true);
}


