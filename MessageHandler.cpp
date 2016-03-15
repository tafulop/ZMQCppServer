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

/* Creates response based on the request */
std::string MessageHandler::createResponse(std::string request){

    // now it sends back the received string
    std::cout << "Message response created: " << request << std::endl;
    return request;
}


/* Converts ZMQ message to string */
std::string MessageHandler::convertMessage(zmq::message_t* msg){
    
    std::string rpl = std::string(static_cast<char*>(msg->data()), msg->size());
    std::cout << "Message converted into: " << rpl << std::endl;
    return rpl;
}

/* Builds ZMQ message from a string */
zmq::message_t MessageHandler::buildMessage(std::string msgData){
    
    zmq::message_t message (msgData.size());
    memcpy (message.data (), msgData.c_str(), msgData.size());
    std::cout << "Message built: " << msgData << std::endl;
    return message;
}

/* Creates a respone based on a json message */
std::string MessageHandler::createResponse(JSON::Object json_request){
    
    // Get Message type
    MESSAGE_TYPE t = detectMessageType(json_request);
  
    JSON::Object json_response;
    
    switch(t){
        
        case MESSAGE_TYPE::JOINT_DATA   :   json_response = getJointData(json_request);
                                            break;
        default:    return "";
    } 
    
    // serialize json object
    std::string str_response = JSONParser::serializeJSONObject(json_response);
     
    return str_response;
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
    
    // Get angle for joint
    // TO-DO: read angle from partcontainer
    float angle = 0;
    
    // build a new json object with fresh data
    JSON::Object response;
    
    response["JOINT_ID"] = jointId;
    response["ANGLE"] = angle;
    
    return response;

}


/* Detects the type of the given message. */
MessageHandler::MESSAGE_TYPE MessageHandler::detectMessageType(JSON::Object message){
    
    std::string value;
    
    for(std::map<std::string, JSON::Value>::iterator it = message.begin(); it != message.end(); ++it){     
        value = it->second.as_string();
        if(value == "JOINT_DATA")
            return MESSAGE_TYPE::JOINT_DATA;
    }

    // type not found in the message
    return MessageHandler::MESSAGE_TYPE::UNKOWN;
}


