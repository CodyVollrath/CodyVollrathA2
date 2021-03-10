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
    ofstream file(this->outfile);
    file << data;
    file.close();

}

bool FileHandler::doesOutputFileExist() const
{
    ifstream file(this->outfile);
    if (file) {
        return true;
    }
    return false;
}

    bool FileHandler::doesInputFileExist() const
{
    ifstream file(this->infile);
    if (file) {
        return true;
    }
    return false;
}
}

