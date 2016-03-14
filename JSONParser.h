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

    }
    
private:

};

#endif /* JSONPARSER_H */

