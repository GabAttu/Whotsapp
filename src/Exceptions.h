#ifndef WHOTSAPP_EXCEPTIONS_H
#define WHOTSAPP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class MessageTooLongException : public std::invalid_argument {
public:
    explicit MessageTooLongException(const std::string& msg) : std::invalid_argument(msg) {}
};

class UserNotFoundException : public std::invalid_argument {
public:
    explicit UserNotFoundException(const std::string& msg) : std::invalid_argument(msg) {}
};

#endif //WHOTSAPP_EXCEPTIONS_H
