#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"

class Server 
{
public:
    Server();
    void run();

private:
    void handleClient(sf::TcpSocket& clientSocket);

    sf::TcpListener listener;
    AcountManager accountManager;

};

