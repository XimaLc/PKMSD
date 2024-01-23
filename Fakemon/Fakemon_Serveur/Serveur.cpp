#include "Serveur.h"

Server::Server() 
{
    if (listener.listen(8888, sf::IpAddress::Any) != sf::Socket::Done)
    {
        std::cerr << "Failed to bind to port 8888\n";
    }
    accountManager.loadFromFile();

}

void Server::handleClient(sf::TcpSocket& clientSocket) 
{
    // Receive username
    if (clientSocket.receive(usernamePacket) == sf::Socket::Done) 
        std::cerr << "receive username succesfull\n";
    else
        std::cerr << "Failed to receive username\n";
    usernamePacket >> username;

    // Receive password
    if (clientSocket.receive(passwordPacket) == sf::Socket::Done) 
        std::cerr << "receive password succesfull\n";
    else
        std::cerr << "Failed to receive password\n";
    passwordPacket >> password;

    // Authenticate
   isAuthenticated = accountManager.authenticate(username, password);

    // Send authentication result to client
    resultPacket << isAuthenticated;
    if (clientSocket.send(resultPacket) == sf::Socket::Done) 
        std::cerr << "send authentication succesfull\n";
    else
        std::cerr << "Failed to send authentication result\n";

    std::cout << "-----------------------\n";

}



void Server::run() 
{
    std::cout << "Server is listening on port 8888...\n";

    while (true) 
    {
        sf::TcpSocket client;

        if (listener.accept(client) == sf::Socket::Done) 
        {
            std::cout << "Client connected\n";
            handleClient(client);
        }
       
    }
}