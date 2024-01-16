#include "AccountManager.h"

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
        std::cerr << "Error load account file\n";
}

void AccountManager::loadFromFile()
{
    std::ifstream file("accounts.dat", std::ios::in | std::ios::binary);
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
        std::cerr << "Error load account file\n";
}
