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
#include "JSONParser.h"
#include <map>

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
    std::string convertMessage(zmq::message_t* msg);
    
    /**
     * Creates a ZMQ message from a string.
     * 
     * @param msgdata The string that should be sent.
     * @return ZMQ message representing the string passed as argument.
     */
    zmq::message_t buildMessage(std::string msgData);
    
    
    /**
     * Creates a response message for the request. 
     * 
     * @param json_request The request message parsed as a JSON::Object
     * @return A string which contains a serialized JSON::Object.
     */
    std::string createResponse(JSON::Object json_request);
    
    
    
private:
    
    /* Available message types */
    enum MESSAGE_TYPE {UNKOWN, JOINT_DATA};
    
    
    /**
     * Detects the type of the message.
     * 
     * @param message 
     * @return The type of the message.
     */
    MESSAGE_TYPE detectMessageType(JSON::Object message);
    
    /**
     * Returns the data for a joint.
     * 
     * @param message The message, that contains the ID of the joint.
     * @return A JSON object, that contains the data about the Joint.
     */
    JSON::Object getJointData(JSON::Object message);
    

    /**
     * Default constructor.
     */
    MessageHandler();
};

#endif /* MESSAGEHANDLER_H */

