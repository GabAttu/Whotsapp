//
// Created by Gabriele on 19/01/2026.
//

#include "Chat.h"
#include <stdexcept>

Chat::Chat(User& u1, User& u2, const std::string& name) : user1(u1), user2(u2), name(name) {}

void Chat::addMessage(const Message& msg) {
    if ((msg.getSender() == user1.getName() && msg.getReceiver() == user2.getName()) ||
        (msg.getSender() == user2.getName() && msg.getReceiver() == user1.getName())) {
        messages.push_back(msg);
    } else {
        throw std::invalid_argument("Message participants do not match chat participants");
    }
}

void Chat::removeMessage(int index) {
    if (index >= 0 && index < messages.size()) {
        messages.erase(messages.begin() + index);
    } else {
        throw std::out_of_range("Message index out of range");
    }
}

const std::vector<Message>& Chat::getMessages() const {
    return messages;
}

const User& Chat::getUser1() const {
    return user1;
}

const User& Chat::getUser2() const {
    return user2;
}

const std::string& Chat::getName() const {
    return name;
}
