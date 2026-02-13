#include <iostream>
#include <stdexcept>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ProgramManager/ProgramManager.h"
#include "TextUserInterface/TextUserInterface.h"

int main() {
    try {

        // users

        auto gabriele = new User("Gabriele");
        auto serena = new User("Serena");
        auto alessandro = new User("Alessandro");
        auto elena = new User("Elena");

        ProgramManager program(*gabriele);
        program.addUser(*serena);
        program.addUser(*alessandro);
        program.addUser(*elena);

        auto chat1 = new Chat(*gabriele, *serena, "Serena <3");
        auto chat2 = new Chat(*gabriele, *alessandro, "Alessandro");
        auto chat3 = new Chat(*elena, *alessandro, "Alessandro");
        auto chat4 = new Chat(*elena, *gabriele, "Sorella");


        auto text1 = new Message("Gabriele", "Serena", "Ciao amore, sono quasi arrivata!", 0);
        auto text2 = new Message("Serena", "Gabriele", "Amore, ti sto aspettando alla stazione", 1);
        auto text3 = new Message("Alessandro", "Gabriele", "Stai studiando?", 2);
        auto text4 = new Message("Gabriele", "Alessandro", "Si, certo...", 3);
        auto text5 = new Message("Elena", "Alessandro", "Ho concluso il secondo capitolo.", 4);
        auto text6 = new Message("Alessandro", "Elena", "Quando cominci il terzo?", 5);
        auto text7 = new Message("Elena", "Alessandro", "Oggi mi riposo.", 6);
        auto text10 = new Message ("Gabriele", "Elena", "Sto arrivando a Firenze.", 7);
        auto text8 = new Message("Elena", "Gabriele", "Vengo a prenderti a Santa Maria Novella.", 8);
        auto text9 = new Message("Gabriele", "Elena", "Okay, grazie.", 9);

        chat1->addMessage(*text1);
        chat1->addMessage(*text2);
        chat3->addMessage(*text5);
        chat3->addMessage(*text6);
        chat3->addMessage(*text7);
        chat4->addMessage(*text10);
        chat4->addMessage(*text8);
        chat4->addMessage(*text9);
        chat2->addMessage(*text3);
        chat2->addMessage(*text4);

        gabriele->addChat(*chat1);
        serena->addChat(*chat1);
        alessandro->addChat(*chat2);
        gabriele->addChat(*chat2);
        gabriele->addChat(*chat4);
        alessandro->addChat(*chat3);
        elena->addChat(*chat3);
        elena->addChat(*chat4);


        TextUserInterface interface(&program);
        interface.beginProgram();
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }

    return 0;
}
