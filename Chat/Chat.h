//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_CHAT_H
#define WHOTSAPP_CHAT_H

#include <vector>
#include "../User/User.h"
#include "../Message/Message.h"

class Chat {
public:
    Chat(const User& user1, const User& user2);

    void addMessage(const Message& msg);
    const std::vector<Message>& getMessages() const;
    const User& getUser1() const;
    const User& getUser2() const;

private:
    const User& user1;
    const User& user2;
    std::vector<Message> messages;
};

#endif //WHOTSAPP_CHAT_H