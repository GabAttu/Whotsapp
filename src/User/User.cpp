//
// Created by Gabriele on 19/01/2026.
//

#include "User.h"
User::User(const std::string& name) : name(name) {}

std::string User::getName() const { return name; }

void User::setName(const std::string& newName) {
    name = newName;
}

void User::addChat(Chat& chat) {
    chats.push_back(&chat);
}

const std::vector<Chat*>& User::getChats() const {
    return chats;
}

bool User::operator==(const User& other) const {
    return name == other.name;
}