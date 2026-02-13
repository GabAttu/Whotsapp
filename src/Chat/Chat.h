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
    Chat(User& user1, User& user2, const std::string& name);

    void addMessage(const Message& msg);
    void removeMessage(int index);
    const std::vector<Message>& getMessages() const;
    const User& getUser1() const;
    const User& getUser2() const;
    const std::string& getName() const;

private:
    User& user1;
    User& user2;
    std::string name;
    std::vector<Message> messages;
};

#endif //WHOTSAPP_CHAT_H