#pragma once
#include <iostream>
#include "SFML/Network.hpp"

class Client
{
public:
    Client();
    void run();

    sf::TcpSocket socket;
};

