/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageHandler.cpp
 * Author: fulop
 * 
 * Created on March 14, 2016, 2:34 PM
 */

#include "MessageHandler.h"

MessageHandler::MessageHandler() {
}

MessageHandler::MessageHandler(const MessageHandler& orig) {
}

MessageHandler::~MessageHandler() {
}


/* Singleton */
MessageHandler& MessageHandler::getInstance(){ 
    static MessageHandler instance;
    return instance;
}


/* Creates a respone based on a json message */
std::shared_ptr<JSON::Object> MessageHandler::createResponse(JSON::Object json_request){
    
    std::cout << "Creating response..." << std::endl;
    
    // Get Message type
    MESSAGE_TYPE t = detectMessageType(json_request);
  
    std::shared_ptr<JSON::Object> json_response;
    
    
    switch(t){
        
        case MESSAGE_TYPE::JOINT_DATA_REQ   :   json_response = std::make_shared<JSON::Object>(getJointData(json_request));
                                                break;
        default:    return nullptr;
    } 
    
    
    
    std::cout << "Creating response... DONE" << std::endl;
     
    return json_response;
}


/* Returns joint data for the joint addressed in the message */
JSON::Object MessageHandler::getJointData(JSON::Object message){
    
    // get Joint ID first
    std::string jointId;
    
    for(std::map<std::string, JSON::Value>::iterator it = message.begin(); it != message.end(); ++it){       
        if(it->first == "JOINT_ID"){
            jointId = it->second.as_string();
            break;
        }
    }
    
    // Get angle from joint
    try{
        
        float angle = this->partManager.joints.get(jointId)->getAngle();
        
        // build a new json object with fresh data
        JSON::Object response;

        response["JOINT_ID"] = jointId;
        response["ANGLE"] = angle;

        return response;
        
        
    } catch(std::out_of_range oor){
        // joint with this ID not found -> error message
        JSON::Object response;
        
        response["MESSAGE_TYPE"] = "ERROR_MESSAGE";
        response["DESCRIPTION"] = "No joint found with id: " + jointId;
        
        return response;
    }
   
}


/* Detects the type of the given message. */
MessageHandler::MESSAGE_TYPE MessageHandler::detectMessageType(JSON::Object message){
    
    
    std::string value;
    
    for(std::map<std::string, JSON::Value>::iterator it = message.begin(); it != message.end(); ++it){     
        if(it->first == "MESSAGE_TYPE"){
            if(it->second.as_string() == "JOINT_DATA_REQ")
            std::cout << "Message type is: JOINT_DATA_REQ" << std::endl;    
            return MESSAGE_TYPE::JOINT_DATA_REQ;
        }
        
    }

    // type not found in the message
    std::cout << "Unknown message type." << std::endl;
    return MessageHandler::MESSAGE_TYPE::UNKOWN;
}


