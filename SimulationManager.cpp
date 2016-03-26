/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationManager.cpp
 * Author: fulop
 * 
 * Created on March 26, 2016, 8:08 PM
 */

#include "SimulationManager.h"

SimulationManager::SimulationManager() {
}

SimulationManager::~SimulationManager() {
}

SimulationManager& SimulationManager::getInstance(){
    static SimulationManager instance;
    return instance;
}

void SimulationManager::enableSimulation(){
    
    // set flag
    this->simulationEnabled = true;
    
    // start socket server
    this->server.runServer();

}

void SimulationManager::disableSimulation(){

    // reset flag
    this->simulationEnabled = false;
    
    // stop socket server
    this->server.stopServer();

}


void SimulationManager::joinToServerThread(){
    this->server.joinThread();
}