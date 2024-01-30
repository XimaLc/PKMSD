#include "Serveur.h"

void Server::Init()
{    
    accountManager.loadFromFile();
  
    listener.listen(8888, sf::IpAddress::Any);
    listener.setBlocking(false);
    selector.add(listener);		

    srand(static_cast<unsigned>(time(NULL)));
}

void Server::Update()
{
    while (!done)	
    {
        TCP();		
    }

}

void Server::TCP()
{
    restartClock();
    for (int i = 0; i < Players.size(); i++)
    {
        Players[i]->timeout += GetDeltaTime();
    }

    if (selector.wait())
    {
        restartClock();
        if (selector.isReady(listener))
        {
            auto clientSocket = std::make_unique<sf::TcpSocket>();
            listener.accept(*clientSocket);
            selector.add(*clientSocket);

            auto newPlayer = std::make_unique<Player>();
            newPlayer->id = clientsNbr;

            if (clientSocket->receive(receivePacket) == sf::Socket::Done)
            {
                int pType;
                receivePacket >> pType >> newPlayer->username >> newPlayer->password;

                if (pType == packetType::LOGIN)
                {
                    newPlayer->isAuthenticated = accountManager.authenticate(newPlayer->username, newPlayer->password);

                    sendPacket << packetType::LOGIN << newPlayer->isAuthenticated;
                    if (clientSocket->send(sendPacket) == sf::Socket::Done)
                        std::cerr << "send authentication succesfull\n" << newPlayer->isAuthenticated << std::endl;
                    else
                        std::cerr << "Failed to send authentication result\n";

                    if (newPlayer->isAuthenticated)
                    {
                        Players.push_back(std::move(newPlayer));
                        clients.push_back(std::move(clientSocket));
                        clientsNbr++;
                    }
                    else
                        selector.remove(*clientSocket); 
                    
                }
                else if (pType == packetType::REGISTER)
                {
                    newPlayer->isRegister = accountManager.registerAccount(newPlayer->username, newPlayer->password);

                    sendPacket << packetType::REGISTER << newPlayer->isRegister;
                    if (clientSocket->send(sendPacket) == sf::Socket::Done)
                        std::cerr << "send register succesfull\n" << newPlayer->isRegister << std::endl;
                    else
                        std::cerr << "Failed to send register result\n";

                    selector.remove(*clientSocket);
                }

                sendPacket.clear();
                receivePacket.clear();
            }
           /* for (int j = 0; j < Players.size(); j++)
            {

                if (Players[j]->id != newPlayer->id)
                {

                }
            }*/

           
        }
        
        /*for (int i = 0; i < clients.size(); i++)
        {   
            if (GetDeltaTime() < 1.0f)
                Players[i]->timeout += GetDeltaTime();
            if (Players[i]->timeout > 1.0f)
            {
                cout << Players[i]->username << " is disconnected" << endl;

                sendPacket << packetType::CLIENT_DISCONNECTED << Players[i]->id;
                for (int j = 0; j < clients.size(); j++)
                {
                    clients[j]->send(sendPacket);
                }

                selector.remove(*clients[i]);
                clients[i]->disconnect();
                clients.erase(clients.begin() + i);
                Players.erase(Players.begin() + i);
            }
        }*/

    }
}


