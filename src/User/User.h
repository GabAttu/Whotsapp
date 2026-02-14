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
    // Costruttore: crea un utente con un nome
    explicit User(const std::string& name);

    // Restituisce il nome dell'utente
    std::string getName() const;
    // Cambia il nome dell'utente
    void setName(const std::string& newName);

    // Aggiunge una chat alla lista dell'utente
    void addChat(Chat& chat);
    // Restituisce la lista delle chat dell'utente
    const std::vector<Chat*>& getChats() const;

    // Operatore di uguaglianza basato sul nome
    bool operator==(const User& other) const;

private:
    std::string name;
    std::vector<Chat*> chats;
};

#endif //WHOTSAPP_USER_H