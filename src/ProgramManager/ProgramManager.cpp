#include "ProgramManager.h"

ProgramManager::ProgramManager(User& user) : currentUser(user) {
    allUsers.push_back(&user);
}

void ProgramManager::addUser(User& user) {
    allUsers.push_back(&user);
}

User& ProgramManager::getCurrentUser() const {
    return currentUser;
}

const std::vector<User*>& ProgramManager::getAllUsers() const {
    return allUsers;
}
