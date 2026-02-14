//
// Created by Gabriele on 19/01/2026.
//

#include "Message.h"

Message::Message(const std::string& sender, const std::string& receiver, const std::string& text, int id)
    : sender(sender), receiver(receiver), text(text), id(id), readStatus(false) {
    if (text.length() > MAX_LENGTH) {
        throw MessageTooLongException("Message exceeds maximum length of " + std::to_string(MAX_LENGTH) + " characters");
    }
    timestamp = std::time(nullptr);
}

const std::string& Message::getSender() const {
    return sender;
}

const std::string& Message::getReceiver() const {
    return receiver;
}

const std::string& Message::getText() const {
    return text;
}

int Message::getId() const {
    return id;
}

std::time_t Message::getTimestamp() const {
    return timestamp;
}

bool Message::isRead() const {
    return readStatus;
}

void Message::setRead(bool read) {
    readStatus = read;
}
