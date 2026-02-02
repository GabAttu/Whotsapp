//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_MESSAGE_H
#define WHOTSAPP_MESSAGE_H

#include <string>
#include <ctime>
#include "../User/User.h"

class Message {
public:
    Message(const User& sender, const User& receiver, const std::string& text);

    const User& getSender() const;
    const User& getReceiver() const;
    const std::string& getText() const;
    std::time_t getTimestamp() const;

private:
    User sender;
    User receiver;
    std::string text;
    std::time_t timestamp;
};

#endif //WHOTSAPP_MESSAGE_H