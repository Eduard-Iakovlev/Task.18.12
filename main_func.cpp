#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include "User.h"
#include "Message.h"

// ������� ��� ��������� ���� ������� � �����
void setFilePermissions(const char* filename) {
    // ������������� ����� ������� 0600 (������ � ������ ������ ���������)
    chmod(filename, S_IRUSR | S_IWUSR);
}

int main() {
    setlocale(LC_ALL, "Russia");
    // ��� ����� ��� User
    const char* userFileName = "user.dat";

    // ��� ����� ��� Message
    const char* messageFileName = "message.dat";

    // ������� ������� User � Message
    User user;
    std::string name, login, pass;
    std::cout << "Enter ���: ";
    std::cin >> name;
    std::cout << "Enter login: ";
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> pass;
    user.addUser(name, login, pass);

    Message message;
    std::string text, receiver;
    std::cout << "Enter message: ";
    std::cin >> text;
    message.addMessage(text);
    std::cout << "Enter name receiver: ";
    std::cin >> receiver;
    message.addReceiver(receiver);
    message.addSender(name);

    // ���������� ������ � ����� � ������� �������
    std::ofstream userFile(userFileName);
    if (userFile.is_open()) {
        userFile << user.rec_name() << "\n";
        userFile << user.rec_login() << "\n";
        userFile << user.rec_pass() << "\n";
        userFile.close();

        // ������������� ����� ������� � �����
        setFilePermissions(userFileName);
    }
    else {
        std::cerr << "Unable to open user file for writing." << "\n";
        return 1;
    }

    std::ofstream messageFile(messageFileName);
    if (messageFile.is_open()) {
        messageFile << message.rec_text() << "\n";
        messageFile << message.rec_sender() << "\n";
        messageFile << message.rec_receiver() << "\n";
        messageFile.close();

        // ������������� ����� ������� � �����
        setFilePermissions(messageFileName);
    }
    else {
        std::cerr << "Unable to open message file for writing." << std::endl;
        return 1;
    }

    // ������ ������ �� ������
    std::ifstream userFileRead(userFileName);
    if (userFileRead.is_open()) {
        std::string name, login, pass;
        userFileRead >> name >> login >> pass;
        userFileRead.close();

        User loadedUser;
        loadedUser.addUser(name, login, pass);

        // ����� ����������� ������
        std::cout << "\n\n Print data from filesdada\n\n";
        std::cout << "Loaded User:\n";
        std::cout << "Name: " << loadedUser.rec_name() << "\n";
        std::cout << "Login: " << loadedUser.rec_login() << "\n";
        std::cout << "Password: " << loadedUser.rec_pass() << "\n";
    }
    else {
        std::cerr << "Unable to open user file for reading." << std::endl;
        return 1;
    }

    std::ifstream messageFileRead(messageFileName);
    if (messageFileRead.is_open()) {
        std::string text, sender, receiver;
        messageFileRead >> text >> sender >> receiver;
        messageFileRead.close();

        Message loadedMessage;
        loadedMessage.addMessage(text);
        loadedMessage.addSender(sender);
        loadedMessage.addReceiver(receiver);

        // ����� ����������� ������
        std::cout << "Loaded Message:\n";
        std::cout << "Text: " << loadedMessage.rec_text() << "\n";
        std::cout << "Sender: " << loadedMessage.rec_sender() << "\n";
        std::cout << "Receiver: " << loadedMessage.rec_receiver() << "\n";
    }
    else {
        std::cerr << "Unable to open message file for reading." << std::endl;
        return 1;
    }


}