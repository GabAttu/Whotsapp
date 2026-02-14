#ifndef WHOTSAPP_PROGRAMMANAGER_H
#define WHOTSAPP_PROGRAMMANAGER_H

#include <vector>
#include "../User/User.h"

class ProgramManager {
public:
    // Costruttore: inizializza il manager
    ProgramManager();
    // Aggiunge un utente al sistema
    void addUser(User* user);
    // Restituisce l'utente attualmente loggato (può essere nullptr se non loggato)
    User* getCurrentUser() const;
    // Imposta l'utente corrente (login)
    void setCurrentUser(User* user);
    // Restituisce la lista di tutti gli utenti registrati
    const std::vector<User*>& getAllUsers() const;
    // Cerca un utente per nome
    User* findUser(const std::string& name) const;

private:
    User* currentUser;
    std::vector<User*> allUsers;
};

#endif //WHOTSAPP_PROGRAMMANAGER_H
