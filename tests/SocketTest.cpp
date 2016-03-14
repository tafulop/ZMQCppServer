/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SocketTest.cpp
 * Author: fulop
 *
 * Created on Mar 13, 2016, 6:15:18 PM
 */

#include "SocketTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(SocketTest);

SocketTest::SocketTest() {
}

SocketTest::~SocketTest() {
}

void SocketTest::setUp() {
}

void SocketTest::tearDown() {
}


/* Full communication test */
void SocketTest::communicationTest(){
    
    
    
    SocketServer::getInstance().runServer();
    std::thread t2 (SocketClient::localClientTest);
    
    t2.join();
    
    CPPUNIT_ASSERT(true);
}