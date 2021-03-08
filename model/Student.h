#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

namespace model
{
class Student
{
    private:
        string firstName;
        string lastName;
        int grade;

    public:
        Student(const string& firstName, const string& lastName, int grade);
        virtual ~Student();

        string getFirstName() const;
        string getLastName() const;
        string getFullName() const;
        int getGrade() const;

    protected:
};
}


#endif // STUDENT_H
