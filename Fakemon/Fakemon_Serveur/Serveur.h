#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"
#include "tools.h"
#include <thread>
#include <vector>

enum packetType
{
    NEW_CONNECTION,
    ON_CONNECTION_ADD_OTHER_PLAYER,
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

    sf::TcpSocket* socket;
    sf::TcpListener listener;
    sf::SocketSelector selector;
    AcountManager accountManager; 

    int id;
    float timeout;
    

    std::vector<Server*> Clients;

    sf::Packet sendPacket;
    sf::Packet receivePacket;
    std::string username;
    std::string password;
    bool isAuthenticated;

};

