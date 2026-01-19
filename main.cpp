#include <iostream>
#include "User/User.h"
#include "Message/Message.h"

int main() {
    User user1("gabri", "Gabriele");
    User user2("alex", "Alessandro");

    Message msg(user1, user2, "Ciao Alessandro, come stai?");

    std::cout << "Mittente: " << msg.getSender().getName() << " (" << msg.getSender().getUsername() << ")" << std::endl;
    std::cout << "Destinatario: " << msg.getReceiver().getName() << " (" << msg.getReceiver().getUsername() << ")" << std::endl;
    std::cout << "Messaggio: " << msg.getText() << std::endl;
    std::time_t ts = msg.getTimestamp();
    std::cout << "Data: " << std::ctime(&ts);

    return 0;
}