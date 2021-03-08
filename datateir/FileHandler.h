#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace datatier
{
class FileHandler
{
    private:
        string infile;
        string outfile;
    public:
        FileHandler(const string& infile, const string& outfile);
        virtual ~FileHandler();
        string read() const;
        void write(const string& data);

    protected:
};
}


#endif // FILEHANDLER_H
