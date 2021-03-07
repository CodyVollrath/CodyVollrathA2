#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
using namespace std;

namespace datatier
{
class CSVParser
{
    private:
        string csvData;
    public:
        CSVParser(const string& csvData);
        virtual ~CSVParser();
        string getOutput() const;

    protected:
};
}


#endif // CSVPARSER_H
