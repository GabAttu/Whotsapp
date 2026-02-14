//
// Created by Gabriele on 19/01/2026.
//

#ifndef WHOTSAPP_MESSAGE_H
#define WHOTSAPP_MESSAGE_H

#include <string>
#include <ctime>
#include "../Exceptions.h"

class Message {
public:
    static const int MAX_LENGTH = 200;
    // Costruttore: crea un messaggio con mittente, destinatario, testo e ID
    Message(const std::string& sender, const std::string& receiver, const std::string& text, int id);

    // Restituisce il mittente
    const std::string& getSender() const;
    // Restituisce il destinatario
    const std::string& getReceiver() const;
    // Restituisce il testo del messaggio
    const std::string& getText() const;
    // Restituisce l'ID del messaggio
    int getId() const;
    // Restituisce il timestamp di creazione
    std::time_t getTimestamp() const;

    // Gestione stato lettura
    bool isRead() const;
    void setRead(bool read);

private:
    std::string sender;
    std::string receiver;
    std::string text;
    int id;
    std::time_t timestamp;
    bool readStatus;
};

#endif //WHOTSAPP_MESSAGE_H