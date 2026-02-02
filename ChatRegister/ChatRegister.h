//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_CHATREGISTER_H
#define WHOTSAPP_CHATREGISTER_H

#include <vector>
#include "../Chat/Chat.h"

class ChatRegister {
public:
    void addChat(const Chat& chat);
    const std::vector<Chat>& getChats() const;
    Chat* findChat(const User& u1, const User& u2);

private:
    std::vector<Chat> chats;
};

#endif //WHOTSAPP_CHATREGISTER_H