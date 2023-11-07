#include "Message.h"

Message::Message(std::string text, std::string sender, std::string receiver):
	_text(text), _sender(sender), _receiver(receiver){}

void Message::addMessage(std::string text){
	_text = text;
}

void Message::addSender(std::string sender){
	_sender = sender;
}

void Message::addReceiver(std::string receiver){
	_receiver = receiver;
}

std::string Message::rec_text(){
	return _text;
}

std::string Message::rec_sender(){
	return _sender;
}

std::string Message::rec_receiver(){
	return _receiver;
}
