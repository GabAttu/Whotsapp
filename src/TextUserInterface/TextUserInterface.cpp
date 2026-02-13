#include "TextUserInterface.h"
#include <iostream>
#include "../Chat/Chat.h"

TextUserInterface::TextUserInterface(ProgramManager* program) : program(program) {}

void TextUserInterface::beginProgram() {
    std::cout << "--- Whotsapp ---" << std::endl;
    if (!program) return;

    User& user = program->getCurrentUser();
    std::cout << "Benvenuto, " << user.getName() << "!" << std::endl;
    std::cout << "Le tue chat:" << std::endl;

    for (const auto& chat : user.getChats()) {
        std::cout << "- " << chat->getName() << " (" << chat->getMessages().size() << " messaggi)" << std::endl;
        for (const auto& msg : chat->getMessages()) {
            std::cout << "  [" << msg.getSender() << "]: " << msg.getText() << std::endl;
        }
    }
}
