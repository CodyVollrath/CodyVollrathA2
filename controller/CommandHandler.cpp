#include <iostream>
#include <regex>
using namespace std;

#include "Roster.h"
#include "Student.h"
using namespace model;

#include "FileHandler.h"
using namespace datatier;


#include "CommandHandler.h"
namespace controller
{
CommandHandler::CommandHandler()
{
    //ctor
}

CommandHandler::~CommandHandler()
{
    //dtor
}

int CommandHandler::processArguments(int argc, char* argv[])
{
    string programName = argv[0];

    for (int i = 1; i < argc; i++) {
        this->arguments.push(string(argv[i]));
    }

    while (!(this->arguments.empty() || this->hasErrors)) {
        string argument = this->arguments.front();

        if (argument == "--help") {
            this->arguments.pop();
            this->displayUsageStatement(programName);
            return 0;
        }

        if (argument[0] != '-') {
            this->determineFiles(argument);
            continue;
        }

        try {
            switch(this->table.at(argument))
            {
                case c: this->handleColumnSpaces();
                break;
                case g: this->enableDisplayStudentGrade();
                break;
                case o: this->disallowOverwritePrompt();
                break;
                case r: this->removeStudentName();
                break;
                case sf: this->sortByFirstName();
                break;
                case sg: this->sortByGrade();
                break;
                default: this->hasErrors = true;
                break;
            }
        } catch (...) {
            this->hasErrors = true;
        }


    }

    if (this->hasErrors) {
        this->displayUsageStatement(programName);
        return 1;
    }

    if (this->inputFile.empty()) {
        cout << "No input file was found"<< endl;
        this->displayUsageStatement(programName);
        return 1;
    }

    FileHandler fileIO(this->inputFile, this->outputFile);
    string fileData = fileIO.read();


    return 0;

}

void CommandHandler::displayUsageStatement(const string& programName)
{
    cout << "Usage: " << programName << " infile [outfile][options]" << endl
         << "Performs a simple grade analysis of the students and grades contained in infile." << endl
         << "\tinfile \t\t The input file to analyze the grades of." << endl
         << "\toutfile \t The output file to write the output to." << endl
         << "options:" << endl
         << "\t--help \t\t Displays this usage statement." << endl
         << "\t-c <number> \t Changes the number of output columns to the number specified." << endl
         << "\t\t\t The default number of columns is 3." << endl
         << "\t-g \t\t Displays student grade with the output." << endl
         << "\t-o \t\t Automatically overwrites the outfile without prompting, if the outfile" << endl
         << "\t\t\t already exists. If this option is not specified and the outfile exists" << endl
         << "\t\t\t the user will be prompted on whether to overwrite the outfile." << endl
         << "\t-r <first last>  Removes the specified student (case insensitive) from the output." << endl
         << "\t\t\t E.g., -r john doe would delete john doe from the output." << endl
         << "\t-sf \t\t Displays the output in alphabetic order by student's first name." << endl
         << "\t\t\t The default order is by student's last name." << endl
         << "\t-sg \t\t Displays the output with the student grade displayed and sorted" << endl
         << "\t\t\t by the student's grade in descending order." << endl;
}

int CommandHandler::getNumberOfColumns(const string& numberArg) const
{
    regex reg("\\d");
    smatch matches;
    int columnSpaces = 0;

    if (regex_search(numberArg, matches, reg))
    {
        int baseTen = 10;
        columnSpaces = stoi(numberArg, nullptr, baseTen);
    }
    return columnSpaces;
}

void CommandHandler::promptUserToOverwrite()
{
    //Display overwrite message;
    //if yes then overwrite.
    //if no do not process.
}
void CommandHandler::determineFiles(const string& filename)
{
    this->arguments.pop();
    if (!this->isInputFileParsed) {
        cout << "Input: " << filename << endl;
        this->inputFile = filename;
        this->isInputFileParsed = true;
        return;
    }
    cout << "Output File: " << filename << endl;
    this->outputFile = filename;
}

void CommandHandler::handleColumnSpaces()
{
    this->arguments.pop();
    if (this->arguments.empty()) {
        cout << "Invalid Argument List. Please see --help." << endl;
        this->hasErrors = true;
        return;
    }

    int numericArg = this->getNumberOfColumns(this->arguments.front());
    if (numericArg == 0) {
        cout << this->arguments.front() << " is not a number. Please see --help." << endl;
        this->hasErrors = true;
        return;
    }

    cout << "Apply numeric value: " << numericArg << " to spaces!"<< endl;
    this->arguments.pop();
}

void CommandHandler::enableDisplayStudentGrade()
{
    this->arguments.pop();
    cout << "Display student grade with the output" << endl;
}

void CommandHandler::disallowOverwritePrompt()
{
    this->arguments.pop();
    this->doNotPromptForOverwrite = true;
}

void CommandHandler::removeStudentName()
{
    this->arguments.pop();

    if (this->arguments.size() < 2) {
        cout << "Invalid Argument List. Please see --help." << endl;
        this->hasErrors = true;
        return;
    }

    string firstName = this->arguments.front();
    this->arguments.pop();
    string lastName = this->arguments.front();
    this->arguments.pop();
    cout << firstName << " : " << lastName << endl;
}

void CommandHandler::sortByFirstName()
{
    this->arguments.pop();
}
void CommandHandler::sortByGrade()
{
    this->arguments.pop();
}
}

