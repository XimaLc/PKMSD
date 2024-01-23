#include "Client.h"

Client::Client()
{
    if (socket.connect("192.168.10.129", 8888) != sf::Socket::Done)
    {
        std::cerr << "Failed to connect to server\n";
    }
}

void Client::run()
{
}
