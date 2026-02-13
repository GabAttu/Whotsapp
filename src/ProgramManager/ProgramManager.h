#ifndef WHOTSAPP_PROGRAMMANAGER_H
#define WHOTSAPP_PROGRAMMANAGER_H

#include <vector>
#include "../User/User.h"

class ProgramManager {
public:
    explicit ProgramManager(User& user);
    void addUser(User& user);
    User& getCurrentUser() const;
    const std::vector<User*>& getAllUsers() const;

private:
    User& currentUser;
    std::vector<User*> allUsers;
};

#endif //WHOTSAPP_PROGRAMMANAGER_H
