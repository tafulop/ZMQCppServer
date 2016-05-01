/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketCommunicator.h
 * Author: fulop
 *
 * Created on March 13, 2016, 4:46 PM
 */

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include "zmq.hpp" // socket communcation
#include <unistd.h> // sleep
#include <iostream> 
#include <thread> // run server as a new thread
#include "MessageHandler.h"
#include "JSONParser.h"
#include <exception>
#include <memory>
#include <mutex>

class SocketServer {
    
public:
    
    /**
     * Singleton get instance member function.
     * @return 
     */
    static SocketServer getInstance();

    
    /**
     * Copy constructor.
     * 
     * @param orig
     */
    SocketServer(const SocketServer& orig);
    
    
    /**
     * Destructor.
     */
    virtual ~SocketServer();
    
    /**
     * Starts the socket server.
     */
    void runServer();
    
    /**
     * Stops the socket server.
     */
    void stopServer();
    
    /**
     * Checks if the server is running.
     * @return true if server is running, false if not.
     */
    bool isRunning();
    
    /**
     * Joins to the server thread.
     */
    void joinThread();
    
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
    
    /* Running flag for the socket server */
    static bool running;
    std::mutex running_flag_mutex;
    
    /* thread to run socket server */
    std::thread serverThread;
    

    /**
     * Listens for new messages for the server.
     * @return 
     */
    static void serverListener();
    
    /**
     * Default constructor.
     */
    SocketServer();
    
};
#endif /* SOCKETSERVER_H */

