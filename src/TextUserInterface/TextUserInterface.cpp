#include "TextUserInterface.h"
#include <iostream>
#include <limits>
#include "../Chat/Chat.h"

TextUserInterface::TextUserInterface(ProgramManager* program) : program(program) {}

void TextUserInterface::beginProgram() {
    while (true) {
        if (program->getCurrentUser() == nullptr) {
            loginMenu();
        } else {
            mainMenu();
        }
    }
}

void TextUserInterface::loginMenu() {
    std::cout << "\n--- Whotsapp Login ---" << std::endl;
    
    auto users = program->getAllUsers();
    if (!users.empty()) {
        std::cout << "Utenti registrati: ";
        for (size_t i = 0; i < users.size(); ++i) {
            std::cout << users[i]->getName() << (i == users.size() - 1 ? "" : ", ");
        }
        std::cout << "\n" << std::endl;
    }

    std::cout << "1. Accedi" << std::endl;
    std::cout << "2. Registrati" << std::endl;
    std::cout << "3. Esci" << std::endl;
    std::cout << "Scelta: ";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::string name;
    switch (choice) {
        case 1:
            std::cout << "Inserisci il tuo nome utente: ";
            std::cin >> name;
            {
                User* user = program->findUser(name);
                if (user) {
                    program->setCurrentUser(user);
                    std::cout << "Login effettuato. Benvenuto " << name << "!" << std::endl;
                } else {
                    std::cout << "Utente non trovato." << std::endl;
                }
            }
            break;
        case 2:
            registerUser();
            break;
        case 3:
            std::cout << "Arrivederci!" << std::endl;
            exit(0);
        default:
            std::cout << "Scelta non valida." << std::endl;
    }
}

void TextUserInterface::registerUser() {
    std::cout << "Inserisci il nuovo nome utente: ";
    std::string name;
    std::cin >> name;
    if (program->findUser(name)) {
        std::cout << "Utente già esistente." << std::endl;
    } else {
        User* newUser = new User(name);
        program->addUser(newUser);
        program->setCurrentUser(newUser);
        std::cout << "Registrazione completata!" << std::endl;
    }
}

void TextUserInterface::mainMenu() {
    User* user = program->getCurrentUser();
    std::cout << "\n--- Menu Principale (" << user->getName() << ") ---" << std::endl;
    std::cout << "1. Visualizza Chat" << std::endl;
    std::cout << "2. Apri Chat" << std::endl;
    std::cout << "3. Messaggi non letti" << std::endl;
    std::cout << "4. Cambia Username" << std::endl;
    std::cout << "5. Cancella un messaggio" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "7. Chiudi Whotsapp" << std::endl;
    std::cout << "Scelta: ";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice) {
        case 1: showChats(); break;
        case 2: openChat(); break;
        case 3: showUnreadMessages(); break;
        case 4: changeUsername(); break;
        case 5: deleteMessage(); break;
        case 6:
            program->setCurrentUser(nullptr);
            std::cout << "Logout effettuato." << std::endl;
            break;
        case 7:
            std::cout << "Arrivederci!" << std::endl;
            exit(0);
        default:
            std::cout << "Scelta non valida." << std::endl;
    }
}

void TextUserInterface::showChats() {
    User* user = program->getCurrentUser();
    auto chats = user->getChats();
    if (chats.empty()) {
        std::cout << "Non hai chat." << std::endl;
        return;
    }
    std::cout << "\nLe tue chat:" << std::endl;
    for (size_t i = 0; i < chats.size(); ++i) {
        std::cout << i + 1 << ". " << chats[i]->getName() << " (" 
                  << chats[i]->getUnreadCount(user->getName()) << " nuovi)" << std::endl;
    }
}

void TextUserInterface::openChat() {
    User* user = program->getCurrentUser();
    auto chats = user->getChats();
    if (chats.empty()) {
        std::cout << "Non hai chat da aprire." << std::endl;
        return;
    }
    showChats();
    std::cout << "Seleziona il numero della chat: ";
    int index;
    std::cin >> index;
    if (index > 0 && index <= (int)chats.size()) {
        Chat* chat = chats[index - 1];
        chat->markAsRead(user->getName());
        std::cout << "\n--- " << chat->getName() << " ---" << std::endl;
        for (const auto& msg : chat->getMessages()) {
            std::cout << "[" << msg.getSender() << "]: " << msg.getText() << std::endl;
        }
    } else {
        std::cout << "Indice non valido." << std::endl;
    }
}

void TextUserInterface::showUnreadMessages() {
    User* user = program->getCurrentUser();
    int total = 0;
    for (auto chat : user->getChats()) {
        int unread = chat->getUnreadCount(user->getName());
        if (unread > 0) {
            std::cout << "- " << unread << " nuovi messaggi in: " << chat->getName() << std::endl;
            total += unread;
        }
    }
    if (total == 0) std::cout << "Non hai messaggi non letti." << std::endl;
}

void TextUserInterface::changeUsername() {
    std::cout << "Inserisci il nuovo username: ";
    std::string newName;
    std::cin >> newName;
    if (program->findUser(newName)) {
        std::cout << "Username già occupato." << std::endl;
    } else {
        program->getCurrentUser()->setName(newName);
        std::cout << "Username aggiornato con successo!" << std::endl;
    }
}

void TextUserInterface::deleteMessage() {
    User* user = program->getCurrentUser();
    auto chats = user->getChats();
    if (chats.empty()) {
        std::cout << "Non hai chat." << std::endl;
        return;
    }
    showChats();
    std::cout << "Seleziona la chat: ";
    int cIdx; std::cin >> cIdx;
    if (cIdx > 0 && cIdx <= (int)chats.size()) {
        Chat* chat = chats[cIdx - 1];
        auto& msgs = chat->getMessages();
        for (size_t i = 0; i < msgs.size(); ++i) {
            std::cout << i + 1 << ". [" << msgs[i].getSender() << "]: " << msgs[i].getText() << std::endl;
        }
        std::cout << "Seleziona il messaggio da eliminare: ";
        int mIdx; std::cin >> mIdx;
        try {
            chat->removeMessage(mIdx - 1);
            std::cout << "Messaggio eliminato." << std::endl;
        } catch (...) {
            std::cout << "Errore nell'eliminazione." << std::endl;
        }
    }
}
