#include <iostream>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ChatRegister/ChatRegister.h"

int main() {
    User user1("gabri", "Gabriele");
    User user2("alex", "Alessandro");
    User user3("giulia", "Giulia");

    Chat chat1(user1, user2);
    Message msg1(user1, user2, "Ciao Alessandro, come stai?");
    Message msg2(user2, user1, "Bene grazie, e tu?");
    chat1.addMessage(msg1);
    chat1.addMessage(msg2);

    Chat chat2(user1, user3);
    Message msg3(user1, user3, "Ciao Giulia!");
    chat2.addMessage(msg3);

    ChatRegister registry;
    registry.addChat(chat1);
    registry.addChat(chat2);

    std::cout << "Registro Chat di Whotsapp" << std::endl;
    std::cout << "==========================" << std::endl;

    for (const auto& chat : registry.getChats()) {
        std::cout << "\nChat tra " << chat.getUser1().getName() 
                  << " e " << chat.getUser2().getName() << ":" << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        for (const auto& msg : chat.getMessages()) {
            std::time_t ts = msg.getTimestamp();
            std::string timeStr = std::ctime(&ts);
            timeStr.pop_back(); // Rimuove \n alla fine

            std::cout << "[" << timeStr << "] " 
                      << msg.getSender().getName() << ": " 
                      << msg.getText() << std::endl;
        }
    }

    std::cout << "\nRicerca chat tra Gabriele e Giulia:" << std::endl;
    Chat* found = registry.findChat(user1, user3);
    if (found) {
        std::cout << "Chat trovata! Numero messaggi: " << found->getMessages().size() << std::endl;
    } else {
        std::cout << "Chat non trovata." << std::endl;
    }

    return 0;
}