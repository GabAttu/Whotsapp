//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_USER_H
#define WHOTSAPP_USER_H
#include <string>
#include <vector>
#include <memory>

class Chat;

class User {
public:

    explicit User(const std::string& name);

    // Restituisce il nome dell'utente
    std::string getName() const;
    // Cambia il nome dell'utente
    void setName(const std::string& newName);

    // Aggiunge una chat alla lista dell'utente
    void addChat(std::shared_ptr<Chat> chat);
    // Restituisce la lista delle chat dell'utente
    const std::vector<std::shared_ptr<Chat>>& getChats() const;

    // Operatore di uguaglianza basato sul nome
    bool operator==(const User& other) const;

private:
    std::string name;
    std::vector<std::shared_ptr<Chat>> chats;
};

#endif //WHOTSAPP_USER_H