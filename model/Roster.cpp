#include "Roster.h"

namespace model
{
Roster::Roster()
{

}

Roster::~Roster()
{
    //dtor
}

void Roster::add(Student& student)
{
    this->students.push_back(student);
}

void Roster::remove(Student& student)
{
    int indexToRemove = this->getIndex(student);
    if (indexToRemove >= 0)
    {
        this->students.erase(this->students.begin() + indexToRemove);
    }
}

Student Roster::getStudent(int index) const
{
    return this->students[index];
}

int Roster::getIndex(Student& student) const
{
    int index = -1;
    for (vector<Student>::size_type i = 0; i < this->students.size(); i++)
    {
        Student currStudent = this->students[i];
        if (student.getFullName() == currStudent.getFullName())
        {
            index = i;
            break;
        }
    }
    return index;
}
Student Roster::getStudent(const string& firstName, const string& lastName) const
{
    string fullName = firstName + " " + lastName;
    for (vector<Student>::size_type i = 0; i < this->students.size(); i++)
    {
        Student currStudent = this->students[i];
        bool equalsIgnoredCase = this->util.strEqualsIgnoreCase(fullName,currStudent.getFullName());
        if (equalsIgnoredCase)
        {

            return currStudent;
        }
    }
    Student emptyStudent("", "", 0);
    return emptyStudent;
}

int Roster::size() const
{
    return this->students.size();
}
void Roster::print()
{
    for (vector<Student>::size_type i = 0; i < this->students.size(); i++)
    {
        cout << this->students[i].getFullName() << endl;
    }
}
void Roster::sortStudentsByLastName()
{
    sort(this->students.begin(), this->students.end());
}

void Roster::sortStudentsByFirstName()
{
    sort(this->students.begin(), this->students.end(), [](Student a, Student b)
    {
        for (char& c1 : a.getFirstName())
        {
            for (char& c2 : b.getFirstName())
            {
                if (c1 < c2)
                {
                    return true;
                }
                else if (c1 > c2)
                {
                    return false;
                }
            }
        }
        return false;
    });
}
void Roster::sortStudentsByGrade()
{
    sort(this->students.begin(), this->students.end(), [](Student a, Student b)
    {
        return a.getGrade() > b.getGrade();
    }); //<- Predicate of some sort
}
}

