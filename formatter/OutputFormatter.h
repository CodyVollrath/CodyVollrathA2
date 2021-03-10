#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Utility.h"
using namespace utility;

#include "Roster.h"
#include "Student.h"
#include "CSVParser.h"
using namespace model;

namespace formatter
{
class OutputFormatter
{
private:
    Utility util;
    string outputData;
    int numberOfColumns;
    bool displayWithNumberGrade;
    Roster roster;
    string getStudentsWithinRange(int maxGrade,int minGrade) const;

public:
    /**
    * Initializes the OutputFormatter class
    * @param roster the roster of students
    * @param numberOfColumns the number of columns for each student to be displayed
    * @param displayWithNumberGrade the flag that indicates if each student should be displayed with a grade
    */
    OutputFormatter(const Roster& roster, int numberOfColumns, bool displayWithNumberGrade);

    /**
    * Deconstructs the OutputFormatter object
    */
    virtual ~OutputFormatter();

    /**
    * Gets the formatted output from the data members
    * @return the formatted output
    */
    string produceOutput() const;

protected:

};
}


#endif // OUTPUTFORMATTER_H
