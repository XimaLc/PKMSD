#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

class AccountManager 
{
private:
    struct Account { std::string username; size_t hashedPassword; };

    std::unordered_map<std::string, Account> accounts;

public:
    bool registerAccount(const std::string& username, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password);

    void saveToFile();
    void loadFromFile();
};

bool AccountManager::registerAccount(const std::string& username, const std::string& password) 
{
    if (accounts.find(username) == accounts.end()) 
    {
        Account newAccount = { username, std::hash<std::string>{}(password) };
        accounts[username] = newAccount;
        saveToFile();
        return true;
    }
    return false;
}

bool AccountManager::authenticate(const std::string& username, const std::string& password) 
{
    auto it = accounts.find(username);
    if (it != accounts.end() && it->second.hashedPassword == std::hash<std::string>{}(password)) 
    {
        return true;
    }
    return false;
}

void AccountManager::saveToFile() 
{
    std::ofstream file("account.dat", std::ios::out | std::ios::binary);
    if (file.is_open()) 
    {
        for (const auto& pair : accounts)
            file << pair.second.username << " " << pair.second.hashedPassword << "\n";
        file.close();
    }
    else
        std::cerr << "Error load account file for save\n";
}

void AccountManager::loadFromFile() 
{
    std::ifstream file("account.dat", std::ios::in | std::ios::binary);
    if (file.is_open()) 
    {
        accounts.clear();
        std::string username;
        size_t hashedPassword;
        while (file >> username >> hashedPassword) 
        {
            Account account{ username, hashedPassword };
            accounts[username] = account;
        }
        file.close();
    }
    else
        std::cerr << "Error load account file for load\n";
}

void handleClient(SOCKET clientSocket, AccountManager& accountManager)
{
    char buffer[1024];
    int bytesRead;

    //username
    bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    std::string username(buffer, bytesRead);

    //password
    bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    std::string password(buffer, bytesRead);

    //Authenticate
    bool isAuthenticated = accountManager.authenticate(username, password);

    send(clientSocket, (isAuthenticated ? "1" : "0"), 2, 0);

    closesocket(clientSocket);
}

int main() 
{
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR) 
    {
        std::cerr << "Failed to initialize Winsock\n";
        return 1;
    }

    // Create socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    // Bind socket
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Bind failed with error\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, 5);

    // Initialize AccountManager
    AccountManager accountManager;
    accountManager.loadFromFile();

    std::cout << "Server is listening on port 8888...\n";

    while (true) {
        // Accept a client socket
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Accept failed with error\n";
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Handle the client in a separate thread or function
        handleClient(clientSocket, accountManager);
    }

    // Clean up
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
