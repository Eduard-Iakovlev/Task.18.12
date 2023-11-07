#pragma once
#include <string>
class User{
public:
    User() = default;
    User(std::string name, std::string login, std::string pass);

    void addUser(std::string name, std::string login, std::string pass);
    std::string rec_name();
    std::string rec_login();
    std::string rec_pass();

private:
    std::string _name;
    std::string _login;
    std::string _pass;
};

