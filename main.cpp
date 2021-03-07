#include <iostream>
using namespace std;

#include "CommandHandler.h"
using namespace controller;

int main(int argc, char* argv[])
{
    CommandHandler commandHandler;
    return commandHandler.processArguments(argc, argv);
}
