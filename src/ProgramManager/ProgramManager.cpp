#include "ProgramManager.h"

ProgramManager::ProgramManager() : currentUser(nullptr) {}

void ProgramManager::addUser(User* user) {
    allUsers.push_back(user);
}

User* ProgramManager::getCurrentUser() const {
    return currentUser;
}

void ProgramManager::setCurrentUser(User* user) {
    currentUser = user;
}

const std::vector<User*>& ProgramManager::getAllUsers() const {
    return allUsers;
}

User* ProgramManager::findUser(const std::string& name) const {
    for (auto user : allUsers) {
        if (user->getName() == name) {
            return user;
        }
    }
    return nullptr;
}
