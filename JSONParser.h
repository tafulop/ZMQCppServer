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
#include <iostream>
#include <sstream>

class JSONParser {
public:
    JSONParser();
    JSONParser(const JSONParser& orig);
    virtual ~JSONParser();
    
    static void test(){
        
        JSON::Object o;
        o["given_name"] = "John";
        o["family_name"] = "Boags";
        
        
        std::cout << o << std::endl;
        
        std::stringstream test;
        
        test << o;
        std::cout << test.str() << std::endl;
        
        
        JSON::Object o2 = parse_string(test.str());
        std::cout << o2 << std::endl;
        
        for(std::map<std::string, JSON::Value>::iterator it = o2.begin(); it != o2.end(); ++it){ 
            
            std::cout << "Key: '" << it->first << "' value: '" << it->second.as_string() << "'" << std::endl;
        }


    }
    
private:

};

#endif /* JSONPARSER_H */

