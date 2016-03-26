/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationManager.h
 * Author: fulop
 *
 * Created on March 26, 2016, 8:08 PM
 */

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "SocketServer.h"

class SimulationManager {
    
public:
    
    /* MEMBER FUNCTIONS*/
    
    /**
     * Enables the simulation by starting the socket server.
     */
    void enableSimulation();
    
    
    /**
     * Enables the simulation by starting the socket server.
     */
    void disableSimulation();
    
    /**
     * Calls the server thread join member function.
     */
    void joinToServerThread();
    
    /**
     * Singleton get instance member function.
     * @return 
     */
    static SimulationManager& getInstance();

    /**
     * Destructor
     */
    virtual ~SimulationManager();
    
private:
    
    /* MEMBER VARIABLES */
    bool simulationEnabled = false;
    
    /* The socket, which maintains the connection with Blender */
    SocketServer server = SocketServer::getInstance();
    
    /**
     * Default constructor is hidden.
     */
    SimulationManager();

};

#endif /* SIMULATIONMANAGER_H */

