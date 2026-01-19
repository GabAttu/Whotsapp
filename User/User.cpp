//
// Created by Gabriele on 19/01/2026.
//

#include "User.h"
User::User(const std::string& username, const std::string& name)
    : username(username), name(name) {}

std::string User::getUsername() const { return username; }
std::string User::getName() const { return name; }