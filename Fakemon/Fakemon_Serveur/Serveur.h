#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"

#include <thread>
#include <vector>

class Server 
{
public:
    Server();
    void run();

private:
    void handleClient(sf::TcpSocket& clientSocket);

    sf::TcpListener listener;
    AcountManager accountManager; 

    std::vector<sf::TcpSocket> connectedClients;

    sf::Packet usernamePacket;
    sf::Packet passwordPacket;
    sf::Packet resultPacket;
    std::string username;
    std::string password;
    bool isAuthenticated;

};

