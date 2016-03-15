/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JSONParser.cpp
 * Author: fulop
 * 
 * Created on March 14, 2016, 8:40 PM
 */

#include "JSONParser.h"
#include "MessageHandler.h"

/* Creates a JSON object from a string */
JSON::Object JSONParser::parseZMQMessage(zmq::message_t* msg){
    
    
    std::string str_msg = MessageHandler::getInstance().convertMessage(msg);
    
    JSON::Object jsonObject = parse_string(str_msg);

    return jsonObject;
}

/* Serializes a JSON object. */
std::string JSONParser::serializeJSONObject(JSON::Object obj){
    
     std::stringstream test;
     test << obj;
     return test.str();
}