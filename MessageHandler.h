/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageHandler.h
 * Author: fulop
 *
 * Created on March 14, 2016, 2:34 PM
 */

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <iostream>
#include <zmq.hpp>

#include "zmq.hpp" // to convert zmq messages

class MessageHandler {
public:
    
    /**
     * Copy constructor.
     * @param orig
     */
    MessageHandler(const MessageHandler& orig);
    
    /**
     * Destructor.
     */
    virtual ~MessageHandler();
    
    /**
     * Singleton get instance member function.
     * @return The one and only instance of MessageHandler.
     */
    static MessageHandler& getInstance();
    
    
    /**
     * Creates a corresponding response message for the request message.
     * @param request The request message in string representation.
     * @return The response for the request as a string.
     */
    std::string createResponse(std::string request);
    
    
    /**
     * Converts the ZMQ message to string.
     * 
     * @param msg The ZMQ message to be converted.
     * @return The string representing the ZMQ message.
     */
    static std::string convertMessage(zmq::message_t* msg);
    
    /**
     * Creates a ZMQ message from a string.
     * 
     * @param msgdata The string that should be sent.
     * @return ZMQ message representing the string passed as argument.
     */
    static zmq::message_t buildMessage(std::string msgData);
    
private:
    
    /**
     * Default constructor.
     */
    MessageHandler();
};

#endif /* MESSAGEHANDLER_H */

