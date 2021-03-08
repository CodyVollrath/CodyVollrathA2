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
    if (indexToRemove >= 0) {
        this->students.erase(this->students.begin() + indexToRemove, this->students.begin() + indexToRemove);
    }
}

Student Roster::getStudent(int index) const
{
    return this->students[index];
}

int Roster::getIndex(Student& student) const
{
    int index = -1;
    for (vector<Student>::size_type i = 0; i < this->students.size(); i++) {
        Student currStudent = this->students[i];
        if (student.getFullName() == currStudent.getFullName()) {
            index = i;
            break;
        }
    }
    return index;
}
Student Roster::getStudent(const string& firstName, const string& lastName) const
{
    string fullName = firstName + " " + lastName;
        for (vector<Student>::size_type i = 0; i < this->students.size(); i++) {
        Student currStudent = this->students[i];
        if (this->util.strEqualsIgnoreCase(fullName,currStudent.getFullName())) {

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
}

