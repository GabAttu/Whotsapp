#include <gtest/gtest.h>
#include "User/User.h"
#include "Message/Message.h"
#include "Chat/Chat.h"
#include "ProgramManager/ProgramManager.h"
#include "Exceptions.h"

// Test per verificare che lo username sia impostato correttamente e che l'uguaglianza tra utenti funzioni
TEST(WhotsappTest, UserEquality) {
    User u1("Gabriele");
    EXPECT_EQ(u1.getName(), "Gabriele");
    
    User u2("Gabriele");
    EXPECT_EQ(u1, u2); // Equality based on name
}

// Test per verificare che i campi del messaggio (mittente, destinatario, testo, ID) siano salvati correttamente
TEST(WhotsappTest, MessageContent) {
    Message m("u1", "u2", "Hello", 1);
    EXPECT_EQ(m.getSender(), "u1");
    EXPECT_EQ(m.getReceiver(), "u2");
    EXPECT_EQ(m.getText(), "Hello");
    EXPECT_EQ(m.getId(), 1);
}

// Test per verificare l'aggiunta di messaggi alla chat e il lancio di eccezioni in caso di partecipanti errati
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

// Test per verificare che gli utenti e il nome della chat siano configurati correttamente
TEST(WhotsappTest, ChatParticipants) {
    User u1("User 1");
    User u2("User 2");
    Chat chat(u1, u2, "Chat Name");

    EXPECT_EQ(chat.getUser1().getName(), "User 1");
    EXPECT_EQ(chat.getUser2().getName(), "User 2");
    EXPECT_EQ(chat.getName(), "Chat Name");
}

// Verifica che venga lanciata un'eccezione se il messaggio è troppo lungo
TEST(WhotsappTest, MessageTooLong) {
    std::string longText(201, 'a');
    EXPECT_THROW(Message("u1", "u2", longText, 1), MessageTooLongException);
}

// Test per verificare la corretta rimozione dei messaggi e la gestione degli errori per indici fuori limite
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

// Test per verificare la gestione dell'utente corrente e della lista utenti nel ProgramManager
TEST(WhotsappTest, ProgramManager) {
    User gabriele("Gabriele");
    User serena("Serena");
    ProgramManager program;
    program.addUser(&gabriele);
    program.addUser(&serena);
    program.setCurrentUser(&gabriele);
    
    EXPECT_EQ(program.getCurrentUser()->getName(), "Gabriele");
    EXPECT_EQ(program.getAllUsers().size(), 2);
}

// Verifica l'aggiunta di una chat a un utente
TEST(WhotsappTest, UserAddChat) {
    User gabriele("Gabriele");
    User serena("Serena");
    Chat chat(gabriele, serena, "Serena <3");
    
    gabriele.addChat(chat);
    EXPECT_EQ(gabriele.getChats().size(), 1);
    EXPECT_EQ(gabriele.getChats()[0]->getName(), "Serena <3");
}

// Test per verificare il corretto conteggio dei messaggi non letti e il funzionamento della marcatura come "letto"
TEST(WhotsappTest, UnreadMessages) {
    User u1("u1");
    User u2("u2");
    Chat chat(u1, u2, "Chat");
    
    Message m1("u1", "u2", "Msg 1", 1); // Destinato a u2
    Message m2("u2", "u1", "Msg 2", 2); // Destinato a u1
    
    chat.addMessage(m1);
    chat.addMessage(m2);
    
    EXPECT_EQ(chat.getUnreadCount("u1"), 1);
    EXPECT_EQ(chat.getUnreadCount("u2"), 1);
    
    // Simula lettura
    const_cast<std::vector<Message>&>(chat.getMessages())[1].setRead(true);
    EXPECT_EQ(chat.getUnreadCount("u1"), 0);
    EXPECT_EQ(chat.getUnreadCount("u2"), 1);
}
