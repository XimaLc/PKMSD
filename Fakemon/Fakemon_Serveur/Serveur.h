#pragma once
#include "SFML/Network.hpp"
#include "AcountManager.h"
#include "tools.h"
#include <thread>
#include <vector>

#include <queue>
#include <mutex>

class Server 
{

private:
    sf::TcpListener listener;
    sf::SocketSelector selector;
    std::vector <std::unique_ptr< sf::TcpSocket >> clients;

    AcountManager accountManager;

    bool connected;
    int tcp_port;
    bool server_started;

    struct Pokemon
    {
        std::string move1;
        std::string move2;
        std::string move3;
        std::string move4;
    };

    struct Team
    {
        std::vector<Pokemon> pokemons;
    };

    struct Player
    {
        sf::IpAddress ip;
        int id;
        std::string username;
        std::string password;
        float timeout;
        bool isAuthenticated = false;
        bool isRegister = false;

        Team team;
    };
    std::vector <std::unique_ptr< Player >> Players;

    sf::Packet sendPacket;
    sf::Packet receivePacket;
    
    bool done = false;
    int clientsNbr = 0;

    enum packetType
    {
        PSEUDO,
        PASSWORD,
        AUTHENTICATE,
        CLIENT_DISCONNECTED,
        LOGIN,
        REGISTER,
        MATCHMAKING,
        POKEMON_ID,
        MOVE_ID
    };

    struct LobbyPlayer
    {
        std::unique_ptr<Player> player;
        sf::TcpSocket socket;
    };
    std::vector<LobbyPlayer> lobbyPlayers;

public:
    void Init();
    void Update();

    void Matchmaking(std::unique_ptr<Player>& requestingPlayer);

    void TCP();

    void HandleClient(std::unique_ptr<sf::TcpSocket> clientSocket);


};


class Room
{
public:
    Room(std::unique_ptr<sf::TcpSocket> player1Socket, std::unique_ptr<sf::TcpSocket> player2Socket);

    void HandlePackets();

private:
    std::unique_ptr<sf::TcpSocket> player1;
    std::unique_ptr<sf::TcpSocket> player2;
};
