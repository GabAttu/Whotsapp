#include <iostream>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"

int main() {
    User user1("gabri", "Gabriele");
    User user2("alex", "Alessandro");

    Chat chat(user1, user2);

    Message msg1(user1, user2, "Ciao Alessandro, come stai?");
    Message msg2(user2, user1, "Bene grazie, e tu?");

    chat.addMessage(msg1);
    chat.addMessage(msg2);

    std::cout << "Chat tra " << chat.getUser1().getName() << " e " << chat.getUser2().getName() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    for (const auto& msg : chat.getMessages()) {
        std::time_t ts = msg.getTimestamp();
        std::string timeStr = std::ctime(&ts);
        timeStr.pop_back(); // Rimuove \n alla fine

        std::cout << "[" << timeStr << "] " 
                  << msg.getSender().getName() << ": " 
                  << msg.getText() << std::endl;
    }

    return 0;
}