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
    /**
    * Initializes the Student Class
    * @param firstName the first name of the Student
    * @param lastName the last name of the student
    * @param grade the grade of the student
    * @pre none
    * @post getFirstName() == firstName AND getLastName() == lastName AND getFullName() == fistName + " " + lastName AND getGrade() == grade
    */
    Student(const string& firstName, const string& lastName, int grade);
    /**
    * Deconstructs the Student object
    */
    virtual ~Student();

    /**
    * Gets the first name of the student
    * @return the first name of the student
    */
    string getFirstName() const;

    /**
    * Gets the last name of the student
    * @return the last name of the student
    */
    string getLastName() const;

    /**
    * Gets the last name of the student
    * @return the last name of the student
    */
    string getFullName() const;

    /**
    * Gets the grade of the student
    * @return the grade of the student
    */
    int getGrade() const;

    /**
    * Sets the default order of students to be by last name
    * @param other the other student to be compared to the student on the right hand side of the operator
    * @return true if the student on the right is after the student on the left alphabetically
    */
    bool operator<(const Student& other) const;

protected:
};
}


#endif // STUDENT_H
