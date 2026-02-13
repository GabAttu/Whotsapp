//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_USER_H
#define WHOTSAPP_USER_H
#include <string>
#include <vector>

class Chat;

class User {
public:
    explicit User(const std::string& name);

    std::string getName() const;

    void addChat(Chat& chat);
    const std::vector<Chat*>& getChats() const;

    bool operator==(const User& other) const;

private:
    std::string name;
    std::vector<Chat*> chats;
};

#endif //WHOTSAPP_USER_H