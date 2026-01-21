//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_USER_H
#define WHOTSAPP_USER_H
#include <string>

class User {
public:
    User(const std::string& username, const std::string& name);

    std::string getUsername() const;
    std::string getName() const;

    bool operator==(const User& other) const;

private:
    std::string username;
    std::string name;
};

#endif //WHOTSAPP_USER_H