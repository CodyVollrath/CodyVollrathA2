#include "CommandHandler.h"

namespace controller
{
CommandHandler::CommandHandler()
{
    this->columns = 3;
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
                case c: this->handleColumns();
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
    CSVParser parser(fileData);
    Roster roster = parser.getRoster();
    if (!this->studentFirstName.empty() && !this->studentLastName.empty()) {
        Student student = roster.getStudent(this->studentFirstName, this->studentLastName);
        roster.remove(student);
    }
    roster.sortStudentsByLastName();
    if (this->doSortByFirstName) {
        roster.sortStudentsByFirstName();
    }

    if (this->doSortByGrade) {
        roster.sortStudentsByGrade();
    }

    OutputFormatter outputFormatter(roster, this->columns, this->displayGrade);
    string output = outputFormatter.produceOutput();
    cout << output << endl;
    if (!this->outputFile.empty()) {
        char response = 'y';
        if (!this->doNotPromptForOverwrite && fileIO.doesOutputFileExist()) {
            cout << "Overwrite" << this->outputFile << "? (y|any key): ";
            cin >> response;
        }
        if (response == 'y') {
            fileIO.write(output);
        }

    }
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
        this->inputFile = filename;
        this->isInputFileParsed = true;
        return;
    }
    this->outputFile = filename;
}

void CommandHandler::handleColumns()
{
    this->arguments.pop();
    if (this->arguments.empty()) {
        cout << "Invalid Argument List. Please see --help." << endl;
        this->hasErrors = true;
        return;
    }

    int numericArg = this->util.convertStrToNum(this->arguments.front());
    if (numericArg == 0) {
        cout << this->arguments.front() << " is not valid. Please see --help." << endl;
        this->hasErrors = true;
        return;
    }
    this->columns = numericArg;
    this->arguments.pop();
}

void CommandHandler::enableDisplayStudentGrade()
{
    this->arguments.pop();
    this->displayGrade = true;
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

    this->studentFirstName = this->arguments.front();
    this->arguments.pop();
    this->studentLastName = this->arguments.front();
    this->arguments.pop();
}

void CommandHandler::sortByFirstName()
{
    this->arguments.pop();
    this->doSortByFirstName = true;
}
void CommandHandler::sortByGrade()
{
    this->arguments.pop();
    this->doSortByGrade = true;
}
}

