#include "OutputFormatter.h"

namespace formatter
{
OutputFormatter::OutputFormatter(const string& csvData)
{
    this->csvData = csvData;
    CSVParser csvParser(csvData);
    this->outputData = csvData;
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}



}

