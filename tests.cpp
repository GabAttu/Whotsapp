#include <iostream>
#include <cassert>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ChatRegister/ChatRegister.h"

void testUser() {
    User u1("gabri", "Gabriele");
    assert(u1.getUsername() == "gabri");
    assert(u1.getName() == "Gabriele");
    
    User u2("gabri", "Different Name");
    assert(u1 == u2); // Equality based on username
    std::cout << "testUser passed!" << std::endl;
}

void testMessage() {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    Message m(u1, u2, "Hello");
    assert(m.getSender().getUsername() == "u1");
    assert(m.getReceiver().getUsername() == "u2");
    assert(m.getText() == "Hello");
    std::cout << "testMessage passed!" << std::endl;
}

void testChat() {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    User u3("u3", "User 3");
    Chat chat(u1, u2);
    
    Message m1(u1, u2, "Hi");
    chat.addMessage(m1);
    assert(chat.getMessages().size() == 1);
    
    Message m2(u2, u1, "Hey");
    chat.addMessage(m2);
    assert(chat.getMessages().size() == 2);
    
    try {
        Message m3(u1, u3, "Wrong");
        chat.addMessage(m3);
        assert(false); // Should not reach here
    } catch (const std::invalid_argument& e) {
        // Correctly caught exception
    }
    std::cout << "testChat passed!" << std::endl;
}

void testChatRegister() {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    User u3("u3", "User 3");
    
    ChatRegister reg;
    Chat chat1(u1, u2);
    Chat chat2(u1, u3);
    
    reg.addChat(chat1);
    reg.addChat(chat2);
    
    assert(reg.getChats().size() == 2);
    
    Chat* found = reg.findChat(u1, u2);
    assert(found != nullptr);
    assert(found->getUser1().getUsername() == "u1" || found->getUser2().getUsername() == "u1");
    
    Chat* notFound = reg.findChat(u2, u3);
    assert(notFound == nullptr);
    std::cout << "testChatRegister passed!" << std::endl;
}

int main() {
    testUser();
    testMessage();
    testChat();
    testChatRegister();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
