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
#include <memory>
#include "../PartContainerLibrary/PartContainerManager.h"

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
     * Creates a response message for the request. 
     * 
     * @param json_request The request message parsed as a JSON::Object
     * @return A string which contains a serialized JSON::Object.
     */
    std::shared_ptr<JSON::Object> createResponse(JSON::Object json_request);
    
    
    
private:
    
    /* Available message types */
    enum MESSAGE_TYPE {UNKOWN, JOINT_DATA_REQ};
    
    /* Robotic Arm Data */
    PartContainerManager& partManager = PartContainerManager::getInstance();
    
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

