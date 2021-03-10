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
    /**
    * Initialize the FileHandler class
    * @param infile the input file
    * @param outfile the output file
    */
    FileHandler(const string& infile, const string& outfile);

    /**
    * Deconstruct the FileHandler object
    */
    virtual ~FileHandler();

    /**
    * Gets the data from the infile
    * @return the data from infile
    */
    string read() const;

    /**
    * Writes to the outfile file
    * @param data the data to be written to the outfile
    */
    void write(const string& data);

    /**
    * Determines if the outfile exists
    * @return true if outfile exists on the system, false otherwise
    */
    bool doesOutputFileExist() const;

    /**
    * Determines if the infile exists
    * @return true if the infile exists on the system, false otherwise
    */
    bool doesInputFileExist() const;

protected:
};
}


#endif // FILEHANDLER_H
