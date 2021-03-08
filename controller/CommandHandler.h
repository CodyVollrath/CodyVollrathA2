#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <iostream>
#include <regex>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

#include <Utility.h>
using namespace utility;

#include "FileHandler.h"
#include "CSVParser.h"
using namespace datatier;

#include "Roster.h"
#include "Student.h"
using namespace model;

#include "OutputFormatter.h"
using namespace formatter;

namespace controller
{
class CommandHandler
{
    private:
        enum ArgumentType {c, g, o, r, sf, sg};
        queue<string> arguments;
        unordered_map<string,ArgumentType> const table =
        {
            {"-c",ArgumentType::c},
            {"-g", ArgumentType::g},
            {"-o", ArgumentType::o},
            {"-r", ArgumentType::r},
            {"-sf", ArgumentType::sf},
            {"-sg", ArgumentType::sg}
        };

        Utility util;
        string inputFile;
        string outputFile;
        bool isInputFileParsed = false;
        bool doNotPromptForOverwrite = false;
        bool hasErrors = false;
        int columns;

        void displayUsageStatement(const string& programName);
        void promptUserToOverwrite();
        void determineFiles(const string& filename);
        void handleColumns();
        void enableDisplayStudentGrade();
        void disallowOverwritePrompt();
        void removeStudentName();
        void sortByFirstName();
        void sortByGrade();
    public:
        CommandHandler();
        virtual ~CommandHandler();
        int processArguments(int argc, char* argv[]);
    protected:
};
}


#endif // COMMANDHANDLER_H
