#include "Serveur.h"

Server server;

int main() 
{
    std::cout << "Server is starting \n";

    server.Init();

    server.Update();

}
