#ifndef WHOTSAPP_PROGRAMMANAGER_H
#define WHOTSAPP_PROGRAMMANAGER_H

#include <vector>
#include <memory>
#include "../User/User.h"

class User;
class Chat;

class ProgramManager {
public:
    
    ProgramManager();
    // Aggiunge un utente al sistema
    void addUser(std::unique_ptr<User> user);
    // Aggiunge una chat al registro globale
    void addChat(std::shared_ptr<Chat> chat);
    
    // Restituisce l'utente attualmente loggato (può essere nullptr se non loggato)
    User* getCurrentUser() const;
    // Imposta l'utente corrente (login)
    void setCurrentUser(User* user);
    // Restituisce la lista di tutti gli utenti registrati
    const std::vector<std::unique_ptr<User>>& getAllUsers() const;
    // Restituisce il registro di tutte le chat
    const std::vector<std::shared_ptr<Chat>>& getAllChats() const;
    // Cerca un utente per nome
    User* findUser(const std::string& name) const;

private:
    User* currentUser;
    std::vector<std::unique_ptr<User>> allUsers;
    std::vector<std::shared_ptr<Chat>> allChats;
};

#endif //WHOTSAPP_PROGRAMMANAGER_H
