#include "CommandHandler.h"
using namespace controller;

int main(int argc, char* argv[])
{
    CommandHandler commandHandler;
    int returnValue = commandHandler.processArguments(argc, argv);
    if (returnValue == 0) {
        commandHandler.displayResult();
    }
    return returnValue;
}
