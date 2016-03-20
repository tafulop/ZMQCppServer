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
#include <memory>

/* Creates a JSON object from a string */
std::shared_ptr<JSON::Object> JSONParser::parseZMQMessage(zmq::message_t* msg){
    
    std::cout << "Parsing ZMQ message..." << std::endl;

    std::shared_ptr<JSON::Object> json_mess;
    std::string str_msg = MessageHandler::getInstance().convertMessage(msg);
    
    std::cout << "string: " << str_msg;
    
    try{
        json_mess = std::make_shared<JSON::Object>(parse_string(str_msg));
        std::cout << "parsing ZMQ message... DONE." << std::endl;
        std::cout << "Created JSON: " << json_mess << std::endl;
        
    }catch(int i){
        std::cout << "Error in parsing: " << str_msg  << std::endl;
    }
    return json_mess;
}

/* Serializes a JSON object. */
std::shared_ptr<std::string> JSONParser::serializeJSONObject(JSON::Object obj){
    
    // Put into stringstream
    std::stringstream test;
    test << obj;
     
    // convert to string
    std::shared_ptr<std::string> serialized = std::make_shared<std::string>(test.str());
     
    return serialized;
}