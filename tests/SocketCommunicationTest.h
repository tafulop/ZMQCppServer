/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SocketCommunicationTest.h
 * Author: fulop
 *
 * Created on Mar 15, 2016, 1:38:37 PM
 */

#ifndef SOCKETCOMMUNICATIONTEST_H
#define SOCKETCOMMUNICATIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../SocketServer.h"
#include "../SocketClient.h"

class SocketCommunicationTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(SocketCommunicationTest);

    CPPUNIT_TEST(testMethod);


    CPPUNIT_TEST_SUITE_END();

public:
    SocketCommunicationTest();
    virtual ~SocketCommunicationTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
};

#endif /* SOCKETCOMMUNICATIONTEST_H */

