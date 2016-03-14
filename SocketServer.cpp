/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketCommunicator.cpp
 * Author: fulop
 * 
 * Created on March 13, 2016, 4:46 PM
 */

#include "SocketServer.h"

/* Default constructor*/
SocketServer::SocketServer() {
}

/* Copy constructor */
SocketServer::SocketServer(const SocketServer& orig) {
}

/* Destructor */
SocketServer::~SocketServer() {
    this->serverThread.~thread();
}

/* Singleton */
SocketServer SocketServer::getInstance(){ 
    static SocketServer instance;
    return instance;
}

/* Starts the socket server */
void SocketServer::runServer(){
    
    // start server
    this->serverThread = std::thread(SocketServer::serverListener);
   
}

/* Listens for new messages */
void SocketServer::serverListener(){
    
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5557");
    MessageHandler& msgHandler = MessageHandler::getInstance();

    while (true) {

        //  Wait for next request from client, blocks
        zmq::message_t request;
        socket.recv (&request);

        // pass the received message to its handler
        std::string str_request = msgHandler.convertMessage(&request);

        //  Creating reply
        std::string str_response = msgHandler.createResponse(str_request);
        
        // if there is anything in response, build message
        if(str_response.empty() == false){
            zmq::message_t response = msgHandler.buildMessage(str_response);
            socket.send (response);
        }   
    }
}


/* Joins to the server thread */
void SocketServer::joinThread(){
    this->serverThread.join();
}



