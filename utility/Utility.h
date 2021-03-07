#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
namespace utility
{
bool strEqualsIgnoreCase(const string& str1, const string& str2)
{
    return equal(str1.begin(), str1.end(),
                 str2.begin(), str2.end(),
                 [](char a, char b) {
                 return tolower(a) == tolower(b);
                 });
}

string* splitStr(const string& str, char delimiter)
{
    string* values;

    return values;
}
}


#endif // UTILITY_H_INCLUDED
