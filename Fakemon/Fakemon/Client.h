#pragma once
#include <iostream>
#include "SFML/Network.hpp"

class Client
{
public:
    Client();
    void run();

    sf::TcpSocket socket;

    enum packetType
    {
        PSEUDO,
        PASSWORD,
        AUTHENTICATE,
        CLIENT_DISCONNECTED,
        LOGIN,
        REGISTER,
        MATCHMAKING
    };
};