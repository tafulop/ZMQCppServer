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
    
    zmq::message_t empty_resp = msgHandler.buildMessage("");
    
    zmq::message_t request;

    while (true) {

        //  Wait for next request from client, blocks
        std::cout << "Waiting for request..." << std::endl;
        socket.recv (&request);

        // Parse the received message as a JSON object
        std::shared_ptr<JSON::Object> json_req = JSONParser::parseZMQMessage(&request);
        
        std::cout << "JSON object received: " << *json_req << std::endl;
       
        // Pass the JSON object to message handler, and get the response message
        std::shared_ptr<std::string> str_response = msgHandler.createResponse(*json_req);

        std::cout << "SocketServer - Response created: " << str_response << std::endl;

        // if there is anything in response, build message
        if(str_response){

            std::cout << "Sending response..." << std::endl;

            zmq::message_t zmq_response = msgHandler.buildMessage(*str_response);

            socket.send (zmq_response);

        }else{
            std::cout << "Empty response will be sent." << std::endl;
            socket.send(empty_resp);
        }   
        
    }
}


/* Joins to the server thread */
void SocketServer::joinThread(){
    this->serverThread.join();
}



