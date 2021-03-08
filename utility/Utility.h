#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;
namespace utility
{
class Utility
{
    public:
        Utility();
        virtual ~Utility();
        bool strEqualsIgnoreCase(const string& str1, const string& str2) const;
        vector<string> splitStr(const string& str, char delimiter) const;
        int convertStrToNum(const string& numStr) const;
        string multiplyStr(const string& str, unsigned int multiplier) const;

    protected:

    private:
};
}


#endif // UTILITY_H
