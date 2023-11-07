#pragma once
#include <string>

class Message{
public:
    Message() = default;
    Message(std::string text, std::string sender, std::string receiver);

    void addMessage(std::string text);
    void addSender(std::string sender);
    void addReceiver(std::string receiver);

    std::string rec_text();
    std::string rec_sender();
    std::string rec_receiver();

private:
    std::string _text;
    std::string _sender;
    std::string _receiver;
};

