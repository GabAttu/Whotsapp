#include <iostream>
#include <stdexcept>
#include <memory>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ProgramManager/ProgramManager.h"
#include "TextUserInterface/TextUserInterface.h"

int main() {
    try {
        ProgramManager program;

        // Popolamento iniziale degli utenti
        auto u1 = std::make_unique<User>("Gabriele");
        auto gabriele = u1.get();
        program.addUser(std::move(u1));

        auto u2 = std::make_unique<User>("Serena");
        auto serena = u2.get();
        program.addUser(std::move(u2));

        auto u3 = std::make_unique<User>("Alessandro");
        auto alessandro = u3.get();
        program.addUser(std::move(u3));

        auto u4 = std::make_unique<User>("Elena");
        auto elena = u4.get();
        program.addUser(std::move(u4));

        // Popolamento iniziale delle chat
        auto chat1 = std::make_shared<Chat>(*gabriele, *serena, "Serena <3");
        auto chat2 = std::make_shared<Chat>(*gabriele, *alessandro, "Alessandro");
        auto chat3 = std::make_shared<Chat>(*elena, *alessandro, "Alessandro");
        auto chat4 = std::make_shared<Chat>(*elena, *gabriele, "Sorella");

        program.addChat(chat1);
        program.addChat(chat2);
        program.addChat(chat3);
        program.addChat(chat4);

        // Messaggi
        chat1->addMessage(Message("Gabriele", "Serena", "Ciao! Come stai?", 0));
        chat1->addMessage(Message("Serena", "Gabriele", "Ehi! Tutto bene, tu?", 1));
        chat2->addMessage(Message("Alessandro", "Gabriele", "Ci vediamo stasera?", 2));
        chat2->addMessage(Message("Gabriele", "Alessandro", "Si, a che ora?", 3));
        chat3->addMessage(Message("Elena", "Alessandro", "Ho finito il progetto.", 4));
        chat3->addMessage(Message("Alessandro", "Elena", "Ottimo lavoro!", 5));
        chat4->addMessage(Message("Gabriele", "Elena", "Sei a casa?", 7));
        chat4->addMessage(Message("Elena", "Gabriele", "Si, arrivo tra poco.", 8));


        gabriele->addChat(chat1);
        serena->addChat(chat1);
        alessandro->addChat(chat2);
        gabriele->addChat(chat2);
        gabriele->addChat(chat4);
        alessandro->addChat(chat3);
        elena->addChat(chat3);
        elena->addChat(chat4);

        TextUserInterface interface(&program);
        interface.beginProgram();

    } catch (const std::exception& e) {
        std::cerr << "Errore fatale: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
