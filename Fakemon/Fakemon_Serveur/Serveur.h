#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"
#include "tools.h"
#include <thread>
#include <vector>



class Server 
{
public:
    void Init();
    void Update();
    
    void TCP();

private:
    sf::TcpListener listener;
    sf::SocketSelector selector;
    std::vector <std::unique_ptr< sf::TcpSocket >> clients;

    AcountManager accountManager;

    bool connected;
    int tcp_port;
    bool server_started;

    struct Player
    {
        sf::IpAddress ip;
        int id;
        std::string username;
        std::string password;
        float timeout;
        bool isAuthenticated = false;
    };
    std::vector <std::unique_ptr< Player >> Players;

    sf::Packet sendPacket;
    sf::Packet receivePacket;
    
    bool done = false;
    int clientsNbr = 0;

    enum packetType
    {
        PSEUDO,
        PASSWORD,
        AUTHENTICATE,
        CLIENT_DISCONNECTED
    };
};

