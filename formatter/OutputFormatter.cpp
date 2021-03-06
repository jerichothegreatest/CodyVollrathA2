#include "OutputFormatter.h"

namespace formatter
{
OutputFormatter::OutputFormatter(const Roster& roster, int numberOfColumns, bool displayWithNumberGrade)
{
    this->roster = roster;
    this->numberOfColumns = numberOfColumns;
    this->displayWithNumberGrade = displayWithNumberGrade;
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

    if (!AStudents.empty())
    {
        output = "Students earning an A:\n" + AStudents + "\n\n";
    }
    if (!BStudents.empty())
    {
        output += "Students earning a B:\n" + BStudents + "\n\n";

    }
    if (!CStudents.empty())
    {
        output += "Students earning a C:\n" + CStudents + "\n\n";
    }
    if (!DStudents.empty())
    {
        output += "Students earning a D:\n" + DStudents + "\n\n";

    }
    if (!FStudents.empty())
    {
        output += "Students earning an F:\n" + FStudents + "\n\n";
    }

    return output;
}
string OutputFormatter::getStudentsWithinRange(int maxGrade,int minGrade) const
{
    string studentsWithinGradeRange;
    stringstream colSeparator;
    unsigned const int COL_WIDTH = 22;
    int colNumber = 0;
    for (int i = 0; i < this->roster.size(); i++)
    {

        Student currStudent = this->roster.getStudent(i);
        string firstName = this->util.convertToUpperCamelCase(currStudent.getFirstName());
        string lastName = this->util.convertToUpperCamelCase(currStudent.getLastName());
        string fullName = firstName + " " + lastName;

        int grade = currStudent.getGrade();
        string gradeToDisplay;
        if (this->displayWithNumberGrade)
        {
            gradeToDisplay = " (" + to_string(grade) + ")";
        }

        if (grade <= maxGrade && grade >= minGrade)
        {
            colNumber++;
            if (colNumber < this->numberOfColumns)
            {
                colSeparator.clear();
                colSeparator.str(string());
                colSeparator << setw(COL_WIDTH);
            }
            else
            {
                colSeparator.clear();
                colSeparator.str(string());
                colSeparator << "\n";
                colNumber = 0;
            }
            studentsWithinGradeRange += fullName + gradeToDisplay + colSeparator.str();
        }

    }
    return studentsWithinGradeRange;
}
}

