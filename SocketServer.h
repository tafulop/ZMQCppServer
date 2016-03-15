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
     * Joins to the server thread.
     */
    void joinThread();
    

private:

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

