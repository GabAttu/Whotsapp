#ifndef WHOTSAPP_TEXTUSERINTERFACE_H
#define WHOTSAPP_TEXTUSERINTERFACE_H

#include "../ProgramManager/ProgramManager.h"

class TextUserInterface {
public:
    // Costruttore: associa l'interfaccia al program manager
    explicit TextUserInterface(ProgramManager* program);
    // Avvia il loop principale dell'interfaccia utente
    void beginProgram();

private:
    ProgramManager* program;

    void loginMenu();
    void mainMenu();
    void showChats();
    void openChat();
    void showUnreadMessages();
    void changeUsername();
    void deleteMessage();
    void registerUser();
    void showChatRegistry();
};

#endif //WHOTSAPP_TEXTUSERINTERFACE_H
