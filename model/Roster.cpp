#include "Roster.h"
namespace model
{
Roster::Roster()
{
    //ctor
}

Roster::~Roster()
{
    //dtor
}

void Roster::add(const Student& student)
{
    this->students.push_back(student);
}

void Roster::remove(const Student& student)
{
    int indexToRemove = -1;
    for (vector<Student>::size_type i = 0; i < this->students.size(); i++) {
        Student currStudent = this->students[i];
        if (student.getFullName() == currStudent.getFullName()) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove >= 0) {
        this->students.erase(this->students.begin() + indexToRemove, this->students.begin() + indexToRemove);
    }

}
}

