#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
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

        string inputFile;
        string outputFile;
        bool isInputFileParsed = false;
        bool doNotPromptForOverwrite = false;
        bool hasErrors = false;

        void displayUsageStatement(const string& programName);
        void promptUserToOverwrite();
        void determineFiles(const string& filename);
        void handleColumnSpaces();
        void enableDisplayStudentGrade();
        void disallowOverwritePrompt();
        void removeStudentName();
        void sortByFirstName();
        void sortByGrade();

        int getNumberOfColumns(const string& numberArg) const;
    public:
        CommandHandler();
        virtual ~CommandHandler();
        int processArguments(int argc, char* argv[]);
    protected:
};
}


#endif // COMMANDHANDLER_H
