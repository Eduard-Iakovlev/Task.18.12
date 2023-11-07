#include "User.h"


User::User(std::string name, std::string login, std::string pass) :
	_name(name), _login(login), _pass(pass){}

void User::addUser(std::string name, std::string login, std::string pass){
	_name = name;
	_login = login;
	_pass = pass;
}

std::string User::rec_name(){
	return _name;
}

std::string User::rec_login(){
	return _login;
}

std::string User::rec_pass() {
	return _pass;
}
