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

}

