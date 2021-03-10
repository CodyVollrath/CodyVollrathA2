#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <iostream>
using namespace std;

#include "Utility.h"
using namespace utility;

#include "Roster.h"
#include "Student.h"
namespace model
{
/**
* The CSVParser class is responsible for parsing a csv and creating a roster class from that data
* @author Cody Vollrath
*/
class CSVParser
{
private:
    string csvData;
    Utility util;
    Student createStudent(const vector<string>& fields) const;

public:
    /**
    * Initializes CSVParser class
    */
    CSVParser(const string& csvData);

    /**
    * Deconstructs the CSVParser object
    */
    virtual ~CSVParser();

    /**
    * Gets the roster created from the csv data that was passed into it.
    * @return the roster of students
    */
    Roster getRoster() const;


protected:
};
}


#endif // CSVPARSER_H
