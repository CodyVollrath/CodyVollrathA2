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
        Roster roster;
        string getStudentsWithinRange(int maxGrade,int minGrade) const;

    public:
        OutputFormatter(const Roster& roster);
        OutputFormatter(const Roster& roster, int numberOfColumns);
        virtual ~OutputFormatter();
        string produceOutput() const;


    protected:

};
}


#endif // OUTPUTFORMATTER_H
