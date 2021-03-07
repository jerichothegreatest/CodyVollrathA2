#include "FileHandler.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace datatier
{
FileHandler::FileHandler(const string& infile, const string& outfile)
{
    this->infile = infile;
    this->outfile = outfile;
}

FileHandler::~FileHandler()
{
    //dtor
}

string FileHandler::read() const
{
    string line;
    ifstream file(this->infile);
    if (file.is_open()){
        while (getline(file, line)) {
            cout << line << '\n';
        }
    }
    return "";
}

void FileHandler::write()
{

}
}
