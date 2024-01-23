#include "Serveur.h"

Server::Server() 
{
    if (listener.listen(8888) != sf::Socket::Done) 
    {
        std::cerr << "Failed to bind to port 8888\n";
    }
    accountManager.loadFromFile();

}

void Server::handleClient(sf::TcpSocket& clientSocket) 
{
    // Receive username
    sf::Packet usernamePacket;
    if (clientSocket.receive(usernamePacket) != sf::Socket::Done) {
        std::cerr << "Failed to receive username\n";
        return;
    }
    std::string username;
    usernamePacket >> username;

    // Receive password
    sf::Packet passwordPacket;
    if (clientSocket.receive(passwordPacket) != sf::Socket::Done) {
        std::cerr << "Failed to receive password\n";
        return;
    }
    std::string password;
    passwordPacket >> password;

    // Authenticate
    bool isAuthenticated = accountManager.authenticate(username, password);

    // Send authentication result to client
    sf::Packet resultPacket;
    resultPacket << isAuthenticated;
    if (clientSocket.send(resultPacket) != sf::Socket::Done) {
        std::cerr << "Failed to send authentication result\n";
    }
}

void Server::run() 
{
    std::cout << "Server is listening on port 8888...\n";

    while (true) {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done) {
            std::cout << "Client connected\n";
            handleClient(client);
        }
    }
}