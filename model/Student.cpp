#include "Student.h"

namespace model
{
Student::Student(const string& firstName, const string& lastName, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
}

Student::~Student()
{
    //dtor
}

string Student::getFirstName() const
{
    return this->firstName;
}

string Student::getLastName() const
{
    return this->lastName;
}

string Student::getFullName() const
{
    string fullName = this->firstName + " " + this->lastName;
    return fullName;
}

int Student::getGrade() const
{
    return this->grade;
}

bool Student::operator<(const Student& other) const
{
    for (char c1 : this->lastName) {
        for (char c2 : other.lastName) {
            if (c1 < c2) {
                return true;
            } else if (c1 > c2) {
                return false;
            }
        }
    }
    return false;
}

}

