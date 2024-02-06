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

//void Server::Matchmaking(std::unique_ptr<Player>& requestingPlayer)
//{
//    sf::TcpSocket* playerSocket = clients.back().get();
//    clients.pop_back(); 
//
//    lobbyPlayers.push_back({ std::move(requestingPlayer), playerSocket });
//
//    if (lobbyPlayers.size() >= 2)
//    {
//        std::unique_ptr<sf::TcpSocket> player1Socket = std::make_unique<sf::TcpSocket>(std::move(lobbyPlayers[0].socket));
//        std::unique_ptr<sf::TcpSocket> player2Socket = std::make_unique<sf::TcpSocket>(std::move(lobbyPlayers[1].socket));
//
//        Room room(std::move(player1Socket), std::move(player2Socket));
//
//        room.HandlePackets();
//
//        lobbyPlayers.clear();
//    }
//}

void Server::TCP()
{
   /* restartClock();
    for (int i = 0; i < Players.size(); i++)
    {
        Players[i]->timeout += GetDeltaTime();
    }*/

    if (selector.wait())
    {
        restartClock();
        if (selector.isReady(listener))
        {
            auto clientSocket = std::make_unique<sf::TcpSocket>();
            listener.accept(*clientSocket);
            selector.add(*clientSocket);

            std::thread(&Server::HandleClient, this, std::move(clientSocket)).detach();
        }

       /* for (int j = 0; j < Players.size(); j++)
        {
            if (Players[j]->isAuthenticated)
            {
                if (clients[j]->receive(receivePacket) == sf::Socket::Done)
                {
                    int pType;
                    receivePacket >> pType;

                    if (pType == packetType::MATCHMAKING)
                    {
                        Matchmaking(Players[j]);
                    }
                }
            }
        }*/
       
        
       /* for (int i = 0; i < clients.size(); i++)
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

void Server::HandleClient(std::unique_ptr<sf::TcpSocket> clientSocket)
{
    auto newPlayer = std::make_unique<Player>();

    // Recevoir les informations de connexion
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
            newPlayer->isRegister = accountManager.registerAccount(accountManager.lastId++, newPlayer->username, newPlayer->password);

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
}


//Room::Room(std::unique_ptr<sf::TcpSocket> player1Socket, std::unique_ptr<sf::TcpSocket> player2Socket)
//    : player1(std::move(player1Socket)), player2(std::move(player2Socket))
//{
//}


//void Room::HandlePackets()
//{
//    sf::Packet packet;
//    std::cout << "suuuuuu";
//
//    while (true)
//    {
//        if (player1->receive(packet) == sf::Socket::Done)
//        {
//            int pType;
//            packet >> pType;
//        }
//
//        if (player2->receive(packet) == sf::Socket::Done)
//        {
//            int pType;
//            packet >> pType;
//        }
//
//        packet.clear();
//    }
//}
