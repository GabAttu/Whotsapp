#include "ProgramManager.h"

ProgramManager::ProgramManager() : currentUser(nullptr) {}

void ProgramManager::addUser(std::unique_ptr<User> user) {
    allUsers.push_back(std::move(user));
}

void ProgramManager::addChat(std::shared_ptr<Chat> chat) {
    allChats.push_back(chat);
}

User* ProgramManager::getCurrentUser() const {
    return currentUser;
}

void ProgramManager::setCurrentUser(User* user) {
    currentUser = user;
}

const std::vector<std::unique_ptr<User>>& ProgramManager::getAllUsers() const {
    return allUsers;
}

const std::vector<std::shared_ptr<Chat>>& ProgramManager::getAllChats() const {
    return allChats;
}

User* ProgramManager::findUser(const std::string& name) const {
    for (const auto& user : allUsers) {
        if (user->getName() == name) {
            return user.get();
        }
    }
    return nullptr;
}
