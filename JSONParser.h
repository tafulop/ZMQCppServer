/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JSONParser.h
 * Author: fulop
 *
 * Created on March 14, 2016, 8:40 PM
 */

#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "../CustomLibraries/json.hh"
#include "zmq.hpp"
#include <iostream>
#include <sstream>

class JSONParser {
public:
    
    static void test(){
        
        JSON::Object o;
        o["given_name"] = "John";
        o["family_name"] = "Boags";
        o["angle"] = 123.456;
        
        
        std::cout << o << std::endl;
        
        std::stringstream test;
        
        test << o;
        std::cout << test.str() << std::endl;
        
        
        JSON::Object o2 = parse_string(test.str());
        std::cout << o2 << std::endl;
        
        for(std::map<std::string, JSON::Value>::iterator it = o2.begin(); it != o2.end(); ++it){ 
            
            std::cout << "Key: '" << it->first << "' value: '" << it->second.as_string() << "'" << std::endl;
            std::cout << "Key: '" << it->first << "' value: '" << it->second.as_float() << "'" << std::endl;
        }

    }
    
    /**
     * Creates a JSON object from a ZMQ message.
     * 
     * @param msg The received ZMQ message.
     * @return JSON::Object containing the data read from the message.
     */
    static JSON::Object parseZMQMessage(zmq::message_t* msg);
    
    
    /**
     * Creates a string from JSON object.
     * @param obj The object that should be serialized.
     * @return A string with serialized data.
     */
    static std::string serializeJSONObject(JSON::Object obj);
    
private:
    
    

};

#endif /* JSONPARSER_H */

