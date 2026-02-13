#ifndef WHOTSAPP_TEXTUSERINTERFACE_H
#define WHOTSAPP_TEXTUSERINTERFACE_H

#include "../ProgramManager/ProgramManager.h"

class TextUserInterface {
public:
    explicit TextUserInterface(ProgramManager* program);
    void beginProgram();

private:
    ProgramManager* program;
};

#endif //WHOTSAPP_TEXTUSERINTERFACE_H
