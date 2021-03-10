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
/**
* The utility class is responsible for various low level functions that require extra processing
* @author Cody Vollrath
*/
class Utility
{
public:
    /**
    * Initializes the Utility class
    */
    Utility();

    /**
    * Deconstruct the Utility object
    */
    virtual ~Utility();

    /**
    * Check if a string equals another string regardless of case
    *
    */
    bool strEqualsIgnoreCase(const string& str1, const string& str2) const;

    /**
    * Splits the string into a vector of type string
    * @param str the string to be split
    * @param delimiter the character to split the string by
    * @return the vector of strings that resulted from the split
    */
    vector<string> splitStr(const string& str, char delimiter) const;

    /**
    * Converts a string to a number provided it can be converted to a number
    * @pre numStr matches \d
    * @param numStr the string that will be turned into a number
    * @return the integer that was passed in as a string
    */
    int convertStrToNum(const string& numStr) const;

    /**
    * Converts the first character to upper case and the rest of the characters to lowercase
    * @param str the string to be passed in.
    * @return the string but with upper case for the first character and lower case for following characters
    */
    string convertToUpperCamelCase(const string& str) const;
protected:

private:
};
}


#endif // UTILITY_H
