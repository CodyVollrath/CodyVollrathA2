#include "FileHandler.h"
namespace datatier
{
FileHandler::FileHandler(const string& infile, const string& outfile)
{
    this->infile = infile;
    this->outfile = outfile;
}

FileHandler::~FileHandler()
{
    //dtor
}

string FileHandler::read() const
{
    string fileData;
    string line;
    ifstream file(this->infile);
    if (file.is_open()){
        while (getline(file, line)) {
            fileData = fileData + line + "\n";
        }
    }
    return fileData;
}

void FileHandler::write(const string& data)
{

}
}

