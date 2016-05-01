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
#include <memory>

class JSONParser {
    
public:

    /**
     * Creates a JSON object from a ZMQ message.
     * 
     * @param msg The received ZMQ message.
     * @return JSON::Object containing the data read from the message.
     */
    static std::shared_ptr<JSON::Object> deserialize(std::string msg);
    
    
    /**
     * Creates a string from JSON object.
     * @param obj The object that should be serialized.
     * @return A string with serialized data.
     */
    static std::shared_ptr<std::string> serialize(JSON::Object obj);
    
private:
    
    

};

#endif /* JSONPARSER_H */

