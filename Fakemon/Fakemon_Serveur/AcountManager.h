#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class AcountManager
{
private:
    struct Account { int id; std::string username; size_t hashedPassword; };

    std::unordered_map<std::string, Account> accounts;

    

public:
    bool registerAccount(int id, const std::string& username, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password);

    void saveToFile();
    void loadFromFile();
    
    int lastId = 0;
};
