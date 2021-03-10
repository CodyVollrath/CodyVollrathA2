#include "Utility.h"
namespace utility
{
Utility::Utility()
{
    //ctor
}

Utility::~Utility()
{
    //dtor
}
bool Utility::strEqualsIgnoreCase(const string& str1, const string& str2) const
{
        return equal(str1.begin(), str1.end(),
                 str2.begin(), str2.end(),
                 [](char a, char b) {
                 return tolower(a) == tolower(b);
                 });
}

vector<string> Utility::splitStr(const string& str, char delimiter) const
{
    vector<string> elements;
    stringstream ss(str);
    string element;

    while (getline(ss, element, delimiter)) {
        elements.push_back(element);
    }

    return elements;
}
int Utility::convertStrToNum(const string& numStr) const
{
    regex reg("\\d");
    smatch matches;
    if (!regex_search(numStr, matches, reg))
    {
        throw invalid_argument("numStr must contain a valid numeric value within the string");
    }
    int baseTen = 10;
    int numericValue = stoi(numStr, nullptr, baseTen);
    return numericValue;
}

string Utility::convertToUpperCamelCase(const string& str) const
{
    string output = str;
    char firstCharacterUpper = toupper(str[0]);
    output[0] = firstCharacterUpper;
    for (unsigned int i = 1; i < str.size(); i++) {
        output[i] = tolower(str[i]);
    }
    return output;
}
}

