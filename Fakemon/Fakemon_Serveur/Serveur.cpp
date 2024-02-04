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

void Server::Matchmaking()
{
    if (Players.size() >= 2)
    {
        int playerIndex1 = rand() % Players.size();
        int playerIndex2 = rand() % Players.size();

        while (playerIndex2 == playerIndex1)
        {
            playerIndex2 = rand() % Players.size();
        }

        std::unique_ptr<sf::TcpSocket> player1Socket = std::move(clients[playerIndex1]);
        std::unique_ptr<sf::TcpSocket> player2Socket = std::move(clients[playerIndex2]);

        // Créer une "room" avec les sockets des joueurs
        Room room(std::move(player1Socket), std::move(player2Socket));

        // Retirer les joueurs de la liste principale
        Players.erase(Players.begin() + playerIndex1);
        Players.erase(Players.begin() + playerIndex2);

        // Retirer les sockets correspondantes
        clients.erase(clients.begin() + playerIndex1);
        clients.erase(clients.begin() + playerIndex2);

        // Démarrer la gestion des paquets dans la "room"
        room.HandlePackets();
    }
}

void Server::TCP()
{
    restartClock();
    for (int i = 0; i < Players.size(); i++)
    {
        Players[i]->timeout += GetDeltaTime();
    }

    // Accepter les nouvelles connexions
    if (selector.wait())
    {
        restartClock();
        if (selector.isReady(listener))
        {
            // Accepter un nouveau client
            auto clientSocket = std::make_unique<sf::TcpSocket>();
            listener.accept(*clientSocket);
            selector.add(*clientSocket);

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

                        if (pType == packetType::MATCHMAKING)
                        {
                            Matchmaking();
                        }
                    }
                    else
                        selector.remove(*clientSocket); 
                    
                }
                else if (pType == packetType::REGISTER)
                {
                    newPlayer->isRegister = accountManager.registerAccount( accountManager.lastId++ , newPlayer->username, newPlayer->password);

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

Room::Room(std::unique_ptr<sf::TcpSocket> player1Socket, std::unique_ptr<sf::TcpSocket> player2Socket)
    : player1(std::move(player1Socket)), player2(std::move(player2Socket))
{
    // Vous pouvez ajouter des initialisations supplémentaires si nécessaire
}


void Room::HandlePackets()
{
    sf::Packet packet;

    // Boucle de gestion des paquets pour la "room"
    while (true)
    {
        if (player1->receive(packet) == sf::Socket::Done)
        {
            // Traitement du paquet du joueur 1 (vérification du packetType, etc.)
            int pType;
            packet >> pType;
            // ... (Autres traitements en fonction du packetType)
        }

        if (player2->receive(packet) == sf::Socket::Done)
        {
            // Traitement du paquet du joueur 2 (vérification du packetType, etc.)
            int pType;
            packet >> pType;
            // ... (Autres traitements en fonction du packetType)
        }

        // Effacer le contenu du paquet pour la prochaine itération
        packet.clear();
    }
}
