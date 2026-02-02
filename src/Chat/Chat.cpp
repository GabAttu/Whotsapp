//
// Created by Gabriele on 19/01/2026.
//

#include "Chat.h"
#include <stdexcept>

Chat::Chat(const User& u1, const User& u2) : user1(u1), user2(u2) {}

void Chat::addMessage(const Message& msg) {
    if ((msg.getSender() == user1 && msg.getReceiver() == user2) ||
        (msg.getSender() == user2 && msg.getReceiver() == user1)) {
        messages.push_back(msg);
    } else {
        throw std::invalid_argument("Message participants do not match chat participants");
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
