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
    /**
    * Initializes the Roster Class
    */
    Roster();

    /**
    * Deconstructs the Roster object
    */
    virtual ~Roster();
    /**
    * Adds a student to the roster
    * @param student the student to be added to the roster
    * @pre none
    * @post size() == size()@pre + 1
    */
    void add(Student& student);

    /**
    * Removes a specific student from the roster
    * @param student the student to be removed from the roster
    * @pre none
    * @post size() == size()@pre - 1
    */
    void remove(Student& student);

    /**
    * Gets the index where the student passed in resides
    * @param student the student in the roster that pertains to the returned index
    * @return the index of the passed in student, -1 if the student does not exist
    */
    int getIndex(Student& student) const;

    /**
    * Gets the student by the index
    * @param index the index at which the desired student is
    * @return the student that belongs at the index
    */
    Student getStudent(int index) const;

    /**
    * Gets the student by the students first and last name regardless of case
    * @param firstName the first name of the student
    * @param lastName the last name of the student
    * @return the student with the same first name and last name regardless of case,
    * student object with empty first and last with grade of 0 if student is not found
    */
    Student getStudent(const string& firstName, const string& lastName) const;

    /**
    * The size of the roster (number of students in the roster)
    * @return the number of students in the roster
    */
    int size() const;

    /**
    * Sorts the students by last name
    */
    void sortStudentsByLastName();

    /**
    * Sorts the students by first name
    */
    void sortStudentsByFirstName();

    /**
    * Sorts the students by grade (descending)
    */
    void sortStudentsByGrade();

    /**
    * Prints the full name each student in the roster
    */
    void print();
protected:
};
}


#endif // ROSTER_H
