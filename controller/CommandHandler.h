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

/**
* The CommandHandler class is responsible for processing commands sent from the command line
* @author Cody Vollrath
*/
class CommandHandler
{
private:
    //Fields
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
    string studentFirstName;
    string studentLastName;
    bool isInputFileParsed = false;
    bool doNotPromptForOverwrite = false;
    bool hasErrors = false;
    int columns;
    bool displayGrade = false;
    bool doSortByGrade = false;
    bool doSortByFirstName = false;

    //Methods
    void processOptions(const string& argument);
    string displayOutput(const Roster& roster) const;
    Roster getRosterFromFileData(const string& fileData) const;
    void saveToOutFile(FileHandler& fileIO, const string& output);
    void displayUsageStatement(const string& programName);
    void determineFiles(const string& filename);
    void handleColumns();
    void enableDisplayStudentGrade();
    void disallowOverwritePrompt();
    void removeStudentName();
    void sortByFirstName();
    void sortByGrade();


public:
    /**
    * Initializes the command handler class
    */
    CommandHandler();
    /**
    * Deconstructs the command handler object
    */
    virtual ~CommandHandler();

    /**
    * Processes an array of arguments and determines validity of arguments
    * @param argc the number of arguments
    * @param argv the arguments
    * @return the exit status
    */
    int processArguments(int argc, char* argv[]);

    /**
    * Displays a result
    */
    void displayResult();
protected:
};
}


#endif // COMMANDHANDLER_H
