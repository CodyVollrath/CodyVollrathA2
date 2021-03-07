#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H
#include <string>
using namespace std;

#include "Roster.h"
#include "Student.h"
using namespace model;

#include "CSVParser.h"
using namespace datatier;

namespace formatter
{
class OutputFormatter
{
    private:
        string csvData;
        string outputData;
        Roster students;
        void parseCSV();

    public:
        OutputFormatter(const string& csvData);
        virtual ~OutputFormatter();




    protected:

};
}


#endif // OUTPUTFORMATTER_H
