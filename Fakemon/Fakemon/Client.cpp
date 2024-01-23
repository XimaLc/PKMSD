#include "Client.h"

Client::Client()
{
    if (socket.connect("127.0.0.1", 8888) != sf::Socket::Done)
    {
        std::cerr << "Failed to connect to server\n";
    }
}

void Client::run()
{
}
