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