#include <gtest/gtest.h>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ProgramManager/ProgramManager.h"
#include "Exceptions.h"

TEST(WhotsappTest, UserEquality) {
    User u1("Gabriele");
    EXPECT_EQ(u1.getName(), "Gabriele");
    
    User u2("Gabriele");
    EXPECT_EQ(u1, u2); // Equality based on name
}

TEST(WhotsappTest, MessageContent) {
    Message m("u1", "u2", "Hello", 1);
    EXPECT_EQ(m.getSender(), "u1");
    EXPECT_EQ(m.getReceiver(), "u2");
    EXPECT_EQ(m.getText(), "Hello");
    EXPECT_EQ(m.getId(), 1);
}

TEST(WhotsappTest, ChatFunctionality) {
    User u1("u1");
    User u2("u2");
    User u3("u3");
    Chat chat(u1, u2, "Chat 1");
    
    Message m1("u1", "u2", "Hi", 1);
    chat.addMessage(m1);
    EXPECT_EQ(chat.getMessages().size(), 1);
    
    Message m2("u2", "u1", "Hey", 2);
    chat.addMessage(m2);
    EXPECT_EQ(chat.getMessages().size(), 2);
    
    Message m3("u1", "u3", "Wrong", 3);
    EXPECT_THROW(chat.addMessage(m3), std::invalid_argument);
}

TEST(WhotsappTest, ChatParticipants) {
    User u1("User 1");
    User u2("User 2");
    Chat chat(u1, u2, "Chat Name");

    EXPECT_EQ(chat.getUser1().getName(), "User 1");
    EXPECT_EQ(chat.getUser2().getName(), "User 2");
    EXPECT_EQ(chat.getName(), "Chat Name");
}

TEST(WhotsappTest, MessageTooLong) {
    std::string longText(201, 'a');
    EXPECT_THROW(Message("u1", "u2", longText, 1), MessageTooLongException);
}

TEST(WhotsappTest, RemoveMessage) {
    User u1("u1");
    User u2("u2");
    Chat chat(u1, u2, "Chat");
    chat.addMessage(Message("u1", "u2", "Msg 1", 1));
    chat.addMessage(Message("u2", "u1", "Msg 2", 2));
    
    EXPECT_EQ(chat.getMessages().size(), 2);
    chat.removeMessage(0);
    EXPECT_EQ(chat.getMessages().size(), 1);
    EXPECT_EQ(chat.getMessages()[0].getText(), "Msg 2");
    
    EXPECT_THROW(chat.removeMessage(5), std::out_of_range);
}

TEST(WhotsappTest, ProgramManager) {
    User gabriele("Gabriele");
    User serena("Serena");
    ProgramManager program(gabriele);
    program.addUser(serena);
    
    EXPECT_EQ(program.getCurrentUser().getName(), "Gabriele");
    EXPECT_EQ(program.getAllUsers().size(), 2);
}

TEST(WhotsappTest, UserAddChat) {
    User gabriele("Gabriele");
    User serena("Serena");
    Chat chat(gabriele, serena, "Serena <3");
    
    gabriele.addChat(chat);
    EXPECT_EQ(gabriele.getChats().size(), 1);
    EXPECT_EQ(gabriele.getChats()[0]->getName(), "Serena <3");
}
