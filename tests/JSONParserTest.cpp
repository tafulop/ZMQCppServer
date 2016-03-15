/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   JSONParserTest.cpp
 * Author: fulop
 *
 * Created on Mar 14, 2016, 8:54:52 PM
 */

#include "JSONParserTest.h"

#include "../JSONParser.h"


CPPUNIT_TEST_SUITE_REGISTRATION(JSONParserTest);

JSONParserTest::JSONParserTest() {
}

JSONParserTest::~JSONParserTest() {
}

void JSONParserTest::setUp() {
}

void JSONParserTest::tearDown() {
}

void JSONParserTest::testMethod() {
   
    JSONParser::test();
    
    CPPUNIT_ASSERT(true);
}



