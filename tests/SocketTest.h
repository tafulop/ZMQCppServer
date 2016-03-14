/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SocketTest.h
 * Author: fulop
 *
 * Created on Mar 13, 2016, 6:15:18 PM
 */

#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <thread>
#include "../zmq.hpp"

#include "../SocketServer.h"
#include "../SocketClient.h"



class SocketTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(SocketTest);

    CPPUNIT_TEST(communicationTest);

    CPPUNIT_TEST_SUITE_END();

public:
    SocketTest();
    virtual ~SocketTest();
    void setUp();
    void tearDown();

private:
    
    void communicationTest();
    
    
};

#endif /* SOCKETTEST_H */

