#ifndef ROSTER_H
#define ROSTER_H
#include <vector>
#include <string>
#include <unordered_map>

#include "Student.h"
using namespace std;
namespace model
{
class Roster
{
    private:
        vector<Student> students;

    public:
        Roster();
        virtual ~Roster();
        void add(const Student& student);
        void remove(const Student& student);
        Student getStudent(int index) const;
        int getIndex(const Student& student) const;
        Student getStudent(const string& firstName, const string& lastName) const;
        unordered_map<char,vector<Student>> getStudentsByGrade() const;

    protected:
};
}


#endif // ROSTER_H
