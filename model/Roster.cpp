#include "Roster.h"

#include "Utility.h"
using namespace utility;

#include <unordered_map>
using namespace std;
namespace model
{
Roster::Roster()
{

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
    int indexToRemove = this->getIndex(student);
    if (indexToRemove >= 0) {
        this->students.erase(this->students.begin() + indexToRemove, this->students.begin() + indexToRemove);
    }
}

Student Roster::getStudent(int index) const
{
    return this->students[index];
}

int Roster::getIndex(const Student& student) const
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
        if (strEqualsIgnoreCase(fullName,currStudent.getFullName())) {

            return currStudent;
        }
    }
    Student emptyStudent("", "", 0);
    return emptyStudent;
}
unordered_map<char, vector<Student>> Roster::getStudentsByGrade() const
{
    unordered_map<char,vector<Student>> studentsByLetterGrade = {
        {'A', vector<Student>()},
        {'B', vector<Student>()},
        {'C', vector<Student>()},
        {'D', vector<Student>()},
        {'F', vector<Student>()}
    };

    for (vector<Student>::size_type i = 0; this->students.size(); i++) {
            Student currStudent = this->students[i];
            int grade = currStudent.getGrade();
            if (grade >= 90) {
                studentsByLetterGrade['A'].push_back(currStudent);
            } else if (grade >= 80) {
                studentsByLetterGrade['B'].push_back(currStudent);
            } else if (grade >= 70) {
                studentsByLetterGrade['C'].push_back(currStudent);
            } else if (grade >= 60) {
                studentsByLetterGrade['D'].push_back(currStudent);
            } else {
                studentsByLetterGrade['F'].push_back(currStudent);
            }
    }
    return studentsByLetterGrade;
}
}

