#include "Serveur.h"



Server::Server() 
{
    if (listener.listen(8888, sf::IpAddress::Any) == sf::Socket::Done)
        std::cout << "Serveur en ligne" << std::endl;
    else
        std::cerr << "Failed to bind to port 8888\n";

    selector.add(listener);

    accountManager.loadFromFile();

}

void Server::handleClient() 
{
    bool done = false;
    int clientsNbr = 0;

    while (!done)
    {
        restartClock();
        for (int i = 0; i < Clients.size(); i++)
        {
            Clients[i]->timeout += GetDeltaTime();
        }

        if (selector.wait())
        {
            restartClock();
            if (selector.isReady(listener))
            {
                Server* client = new Server();
                client->socket = new TcpSocket();
                listener.accept(*client->socket);
                selector.add(*client->socket);
                client->id = clientsNbr;
                client->timeout = 0.f;

                if (client->socket->receive(receivePacket) == sf::Socket::Done)
                {
                    receivePacket >> client->username;
                    std::cerr << "receive username succesfull\n";
                }
                else
                    std::cerr << "Failed to receive username\n";

                if (client->socket->receive(receivePacket) == sf::Socket::Done)
                {
                    receivePacket >> client->password;
                    std::cerr << "receive password succesfull\n";
                }
                else
                    std::cerr << "Failed to receive password\n";

                client->isAuthenticated = accountManager.authenticate(username, password);

                sendPacket << client->isAuthenticated;
                if (client->socket->send(sendPacket) == sf::Socket::Done)
                    std::cerr << "send authentication succesfull\n";
                else
                    std::cerr << "Failed to send authentication result\n";

                Clients.push_back(client);
                clientsNbr++;

                for (int j = 0; j < Clients.size(); j++)
                {

                    if (Clients[j]->id != client->id)
                    {

                    }
                }
            }
            else
            {

            }
            for (int i = 0; i < Clients.size(); i++)
            {
                if (GetDeltaTime() < 1.0f)
                    Clients[i]->timeout += GetDeltaTime();
                if (Clients[i]->timeout > 1.0f)
                {
                    cout << Clients[i]->username << " is disconnected" << endl;

                    sendPacket << packetType::CLIENT_DISCONNECTED << Clients[i]->id;
                    for (int j = 0; j < Clients.size(); j++)
                    {
                        Clients[j]->socket->send(sendPacket);
                    }
                    selector.remove(*Clients[i]->socket);
                    Clients.erase(Clients.begin() + i);
                }
            }
        }
    }
}



void Server::run() 
{
       handleClient();
}