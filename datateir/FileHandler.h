#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
using namespace std;
namespace datatier
{
class FileHandler
{
    private:
        string infile;
        string outfile;
    public:
        FileHandler(const string& infile, const string& outfile);
        virtual ~FileHandler();
        string read() const;
        void write();

    protected:
};
}


#endif // FILEHANDLER_H
