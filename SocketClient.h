/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketClient.h
 * Author: fulop
 *
 * Created on March 13, 2016, 5:55 PM
 */

#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include "zmq.hpp"
#include <iostream>

#include "MessageHandler.h"

class SocketClient {
    
public:
    
    SocketClient();
    SocketClient(const SocketClient& orig);
    virtual ~SocketClient();
    
    zmq::socket_t* getSocket();
    
    static SocketClient& getInstance();
    
    static void localClientTest();
  
    static void JSONSendingTest();
    
    
private:


};

#endif /* SOCKETCLIENT_H */

