//
// Created by Gabriele on 19/01/2026.
//

#include "ChatRegister.h"

void ChatRegister::addChat(const Chat& chat) {
    chats.push_back(chat);
}

const std::vector<Chat>& ChatRegister::getChats() const {
    return chats;
}

Chat* ChatRegister::findChat(const User& u1, const User& u2) {
    for (auto& chat : chats) {
        if ((chat.getUser1() == u1 && chat.getUser2() == u2) ||
            (chat.getUser1() == u2 && chat.getUser2() == u1)) {
            return &chat;
        }
    }
    return nullptr;
}
