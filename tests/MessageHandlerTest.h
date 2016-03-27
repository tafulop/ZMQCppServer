/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MessageHandlerTest.h
 * Author: fulop
 *
 * Created on Mar 27, 2016, 1:40:32 PM
 */

#ifndef MESSAGEHANDLERTEST_H
#define MESSAGEHANDLERTEST_H

#include "../MessageHandler.h"
#include "../../PartContainerLibrary/PartContainerManager.h"
#include <cppunit/extensions/HelperMacros.h>

class MessageHandlerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MessageHandlerTest);

    CPPUNIT_TEST(jointDataRead);

    CPPUNIT_TEST_SUITE_END();

public:
    MessageHandlerTest();
    virtual ~MessageHandlerTest();
    void setUp();
    void tearDown();

private:
    
    void jointDataRead();

};

#endif /* MESSAGEHANDLERTEST_H */

