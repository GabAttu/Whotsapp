#include <gtest/gtest.h>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ChatRegister/ChatRegister.h"

TEST(WhotsappTest, UserEquality) {
    User u1("gabri", "Gabriele");
    EXPECT_EQ(u1.getUsername(), "gabri");
    EXPECT_EQ(u1.getName(), "Gabriele");
    
    User u2("gabri", "Different Name");
    EXPECT_EQ(u1, u2); // Equality based on username
}

TEST(WhotsappTest, MessageContent) {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    Message m(u1, u2, "Hello");
    EXPECT_EQ(m.getSender().getUsername(), "u1");
    EXPECT_EQ(m.getReceiver().getUsername(), "u2");
    EXPECT_EQ(m.getText(), "Hello");
}

TEST(WhotsappTest, ChatFunctionality) {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    User u3("u3", "User 3");
    Chat chat(u1, u2);
    
    Message m1(u1, u2, "Hi");
    chat.addMessage(m1);
    EXPECT_EQ(chat.getMessages().size(), 1);
    
    Message m2(u2, u1, "Hey");
    chat.addMessage(m2);
    EXPECT_EQ(chat.getMessages().size(), 2);
    
    Message m3(u1, u3, "Wrong");
    EXPECT_THROW(chat.addMessage(m3), std::invalid_argument);
}

TEST(WhotsappTest, ChatParticipants) {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    Chat chat(u1, u2);

    EXPECT_EQ(chat.getUser1().getUsername(), "u1");
    EXPECT_EQ(chat.getUser2().getUsername(), "u2");
    EXPECT_EQ(chat.getUser1().getName(), "User 1");
    EXPECT_EQ(chat.getUser2().getName(), "User 2");
}

TEST(WhotsappTest, ChatRegister) {
    User u1("u1", "User 1");
    User u2("u2", "User 2");
    User u3("u3", "User 3");
    
    ChatRegister reg;
    Chat chat1(u1, u2);
    Chat chat2(u1, u3);
    
    reg.addChat(chat1);
    reg.addChat(chat2);
    
    EXPECT_EQ(reg.getChats().size(), 2);
    
    Chat* found = reg.findChat(u1, u2);
    ASSERT_NE(found, nullptr);
    EXPECT_TRUE(found->getUser1().getUsername() == "u1" || found->getUser2().getUsername() == "u1");
    
    Chat* notFound = reg.findChat(u2, u3);
    EXPECT_EQ(notFound, nullptr);
}
