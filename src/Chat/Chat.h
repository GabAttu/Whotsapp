//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_CHAT_H
#define WHOTSAPP_CHAT_H

#include <vector>
#include "../User/User.h"
#include "../Message/Message.h"

class Chat {
public:

    Chat(User& user1, User& user2, const std::string& name);

    // Aggiunge un messaggio alla chat
    void addMessage(const Message& msg);
    // Rimuove un messaggio dalla chat tramite indice
    void removeMessage(int index);
    // Restituisce la lista dei messaggi della chat
    const std::vector<Message>& getMessages() const;
    // Restituisce il primo partecipante
    const User& getUser1() const;
    // Restituisce il secondo partecipante
    const User& getUser2() const;
    // Restituisce il nome della chat
    const std::string& getName() const;

    // Restituisce il numero di messaggi non letti per un utente
    int getUnreadCount(const std::string& userName) const;

    // Segna i messaggi come letti per un utente
    void markAsRead(const std::string& userName);

private:
    User& user1;
    User& user2;
    std::string name;
    std::vector<Message> messages;
};

#endif //WHOTSAPP_CHAT_H