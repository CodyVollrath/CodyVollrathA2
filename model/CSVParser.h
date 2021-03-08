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
class CSVParser
{
    private:
        string csvData;
        Utility util;
        Student createStudent(const vector<string>& fields) const;

    public:
        CSVParser(const string& csvData);
        virtual ~CSVParser();
        Roster getRoster() const;


    protected:
};
}


#endif // CSVPARSER_H
