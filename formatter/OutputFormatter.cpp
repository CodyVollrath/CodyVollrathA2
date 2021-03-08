#include "OutputFormatter.h"

namespace formatter
{
OutputFormatter::OutputFormatter(const Roster& roster)
{
    this->roster = roster;
    this->numberOfColumns = 3;
}
OutputFormatter::OutputFormatter(const Roster& roster, int numberOfColumns)
{
    this->roster = roster;
    this->numberOfColumns = numberOfColumns;
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}
string OutputFormatter::produceOutput() const
{
    string output;
    string AStudents = this->getStudentsWithinRange(INT_MAX,90);
    string BStudents = this->getStudentsWithinRange(89,80);
    string CStudents = this->getStudentsWithinRange(79,70);
    string DStudents = this->getStudentsWithinRange(69,60);
    string FStudents = this->getStudentsWithinRange(59, INT_MIN);

    if (!AStudents.empty()) {
        output = "Students earning an A:\n" + AStudents + "\n";
    }
    if (!BStudents.empty()) {
        output += "Students earning a B:\n" + BStudents + "\n";

    }
    if (!CStudents.empty()) {
        output += "Students earning a C:\n" + CStudents + "\n";
    }
    if (!DStudents.empty()) {
        output += "Students earning a D:\n" + DStudents + "\n";

    }
    if (!FStudents.empty()) {
        output += "Students earning an F:\n" + FStudents + "\n";
    }

    return output;
}
string OutputFormatter::getStudentsWithinRange(int maxGrade,int minGrade) const
{
    string studentsWithinGradeRange;
    string colSeparator;
    unsigned int columnWidth = 22;
    int colNumber = 0;
    for (int i = 0; i < this->roster.size(); i++) {
        Student currStudent = this->roster.getStudent(i);
        string fullName = currStudent.getFullName();
        int grade = currStudent.getGrade();

        if (grade <= maxGrade && grade >= minGrade) {
            colNumber++;
            if (colNumber < this->numberOfColumns) {
                colSeparator = "\t\t";
            } else {
                colSeparator = "\n";
                colNumber = 0;
            }
            studentsWithinGradeRange += fullName + colSeparator;
        }

    }
    return studentsWithinGradeRange + "\n";
}
}

