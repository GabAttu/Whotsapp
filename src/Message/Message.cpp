//
// Created by Gabriele on 19/01/2026.
//

#include "Message.h"

Message::Message(const User& sender, const User& receiver, const std::string& text)
    : sender(sender), receiver(receiver), text(text) {
    timestamp = std::time(nullptr);
}

const User& Message::getSender() const {
    return sender;
}

const User& Message::getReceiver() const {
    return receiver;
}

const std::string& Message::getText() const {
    return text;
}

std::time_t Message::getTimestamp() const {
    return timestamp;
}
