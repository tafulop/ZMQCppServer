/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketClient.cpp
 * Author: fulop
 * 
 * Created on March 13, 2016, 5:55 PM
 */

#include "SocketClient.h"
#include "SocketServer.h"

SocketClient::SocketClient() {
}

SocketClient::SocketClient(const SocketClient& orig) {
}

SocketClient::~SocketClient() {
}

/* Singleton */
SocketClient& SocketClient::getInstance(){ 
    static SocketClient instance;
    return instance;
}


void SocketClient::localClientTest(){
    
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
    
    MessageHandler& hand = MessageHandler::getInstance();

    std::cout << "Connecting to hello world server…" << std::endl;
    socket.connect ("tcp://localhost:5557");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        
        std::string msgData = "dummy data";
        zmq::message_t request = SocketServer::buildMessage(msgData);
        socket.send (request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv (&reply);
        std::string response = SocketServer::convertMessage(&reply);
        std::cout << "Received by client: " << response << std::endl;
    }

}


void SocketClient::JSONSendingTest(){
    
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
    
    MessageHandler& hand = MessageHandler::getInstance();

    std::cout << "Connecting to the server…" << std::endl;
    socket.connect ("tcp://localhost:5557");
    
    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        
        // creating JSON object
        JSON::Object json_req;
        json_req["MESSAGE_TYPE"] = "JOINT_DATA";
        json_req["JOINT_ID"] = "J1";


        // Converting to string and ZMQ message
        std::shared_ptr<std::string> str_req = JSONParser::serialize(json_req);
        zmq::message_t request = SocketServer::buildMessage(*str_req);
        
        // Send
        socket.send (request);

        //  Get the reply
        zmq::message_t reply;
        socket.recv (&reply);
        std::string response = SocketServer::convertMessage(&reply);
        std::cout << "Received by client: " << response << std::endl;
    }
    
}