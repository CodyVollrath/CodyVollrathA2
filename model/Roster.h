#ifndef ROSTER_H
#define ROSTER_H
#include <vector>
#include <string>

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

    protected:
};
}


#endif // ROSTER_H
