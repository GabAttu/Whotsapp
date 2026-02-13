//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_MESSAGE_H
#define WHOTSAPP_MESSAGE_H

#include <string>
#include <ctime>
#include "../Exceptions.h"

class Message {
public:
    static const int MAX_LENGTH = 200;
    Message(const std::string& sender, const std::string& receiver, const std::string& text, int id);

    const std::string& getSender() const;
    const std::string& getReceiver() const;
    const std::string& getText() const;
    int getId() const;
    std::time_t getTimestamp() const;

private:
    std::string sender;
    std::string receiver;
    std::string text;
    int id;
    std::time_t timestamp;
};

#endif //WHOTSAPP_MESSAGE_H