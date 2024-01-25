#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"
#include "tools.h"
#include <thread>
#include <vector>

enum packetType
{
    LOGIN,
    REGISTER,
    UPDATE_POSITION,
    CLIENT_DISCONNECTED
};
typedef enum packetType packetType;

class Server 
{
public:
    Server();
    void run();

private:
    void handleClient();

    sf::TcpListener listener;
    sf::SocketSelector selector;
    AcountManager accountManager; 

    sf::Packet sendPacket;
    sf::Packet receivePacket;
    
    bool done = false;
    int clientsNbr = 0;
};

