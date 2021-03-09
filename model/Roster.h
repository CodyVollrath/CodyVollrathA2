#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "Utility.h"
using namespace utility;


namespace model
{
class Roster
{
    private:
        vector<Student> students;
        Utility util;

    public:
        Roster();
        virtual ~Roster();
        void add(Student& student);
        void remove(Student& student);
        int getIndex(Student& student) const;
        Student getStudent(int index) const;
        Student getStudent(const string& firstName, const string& lastName) const;
        int size() const;
        void sortStudentsByLastName();
        void sortStudentsByFirstName();
        void sortStudentsByGrade();
        void print();
    protected:
};
}


#endif // ROSTER_H
