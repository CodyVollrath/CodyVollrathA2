#include "CSVParser.h"

namespace model
{
CSVParser::CSVParser(const string& csvData)
{
    this->csvData = csvData;
}

CSVParser::~CSVParser()
{

}
Roster CSVParser::getRoster() const
{
    vector<string> lines = this->util.splitStr(this->csvData, '\n');
    Roster roster;
    for (vector<string>::size_type i = 0; i < lines.size(); i++) {
        vector<string> field = this->util.splitStr(lines[i], ',');
        string firstName = field[1];
        string lastName = field[0];
        int grade = this->util.convertStrToNum(field[2]);
        Student newStudent(firstName, lastName, grade);
        roster.add(newStudent);
    }
    return roster;
}
}

