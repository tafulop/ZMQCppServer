/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   JSONParserTest.h
 * Author: fulop
 *
 * Created on Mar 14, 2016, 8:54:52 PM
 */

#ifndef JSONPARSERTEST_H
#define JSONPARSERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class JSONParserTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(JSONParserTest);

    CPPUNIT_TEST(testMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    JSONParserTest();
    virtual ~JSONParserTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
};

#endif /* JSONPARSERTEST_H */

