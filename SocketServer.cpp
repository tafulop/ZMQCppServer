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

// set default state
bool SocketServer::running = false;

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
    
    std::lock_guard<std::mutex> guard(running_flag_mutex);
    bool l_running_flag = SocketServer::running;
    guard.~lock_guard();
    
    // start only if not running
    if(l_running_flag == false){
        // start server
        serverThread = std::thread(SocketServer::serverListener);

        // set running flag
        SocketServer::running = true;
    }
}

/* Listens for new messages */
void SocketServer::serverListener(){
    
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5557");
    MessageHandler& msgHandler = MessageHandler::getInstance();
    
    zmq::message_t empty_resp = buildMessage("");
    
    zmq::message_t request;

    // loops while data server is running
    while (SocketServer::running == true) {

        //  Wait for next request from client, blocks
        std::cout << "Waiting for request..." << std::endl;
        socket.recv (&request);

        // convert ZMQ message to string
        std::string str_msg = convertMessage(&request);
        
        // Parse the received message as a JSON object
        std::shared_ptr<JSON::Object> json_req = JSONParser::deserialize(str_msg);
        
        std::cout << "JSON object received: " << *json_req << std::endl;
       
        // Pass the JSON object to message handler, and get the response message
        
        std::shared_ptr<JSON::Object> json_response = msgHandler.createResponse(*json_req);

        // serialize json object
        std::shared_ptr<std::string> str_response = JSONParser::serialize(*json_response);
        
        std::cout << "SocketServer - Response created: " << str_response << std::endl;

        // if there is anything in response, build message
        if(str_response){

            std::cout << "Sending response..." << std::endl;

            zmq::message_t zmq_response = buildMessage(*str_response);

            socket.send (zmq_response);

        }else{
            std::cout << "Empty response will be sent." << std::endl;
            socket.send(empty_resp);
        }   
        
    }
    
    // server stopped -> close socket
    socket.close();
}


/* Converts ZMQ message to string */
std::string SocketServer::convertMessage(zmq::message_t* msg){
    
    std::string rpl = std::string(static_cast<char*>(msg->data()), msg->size());
    std::cout << "Message converted into: " << rpl << std::endl;
    return rpl;
}

/* Builds ZMQ message from a string */
zmq::message_t SocketServer::buildMessage(std::string msgData){
    
    zmq::message_t message (msgData.size());
    memcpy (message.data (), msgData.c_str(), msgData.size());
    std::cout << "Message built: " << msgData << std::endl;
    return message;
}

/* Joins to the server thread */
void SocketServer::joinThread(){
    this->serverThread.join();
}

/* Sets the running flag to false */
// TO-DO: handle socket blocking receive related problem
void SocketServer::stopServer(){
    std::lock_guard<std::mutex> guard(SocketServer::running_flag_mutex);
    SocketServer::running= false;
}

/* check if the server is running */
bool SocketServer::isRunning(){
    
    std::lock_guard<std::mutex> guard(SocketServer::running_flag_mutex);
    bool l_running_flag = SocketServer::running;
    guard.~lock_guard();
    
    return l_running_flag;
}

