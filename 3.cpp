#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const Groups& groups)
{
    ofstream out;
    out.open(filename);
    for (auto it = groups.begin(); it != groups.end(); it++)
    {
        out << "#" << it->first << endl;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            out << it2->Name << endl;
            out << it2->Year << endl;
            out << it2->RecordBook.size() << endl;
            for (auto it3 = it2->RecordBook.begin(); it3 != it2->RecordBook.end(); it3++)
            {
                out << it3->first << endl;
                out << it3->second << endl;
            }
        }
    }
    out.close();
}

void loadFromFile(const string& filename, Groups& outGroups)
{
    ifstream in;
    in.open(filename);
    string line, subject, group;
    int record_size = 0;
    Student crStudent;

    while (getline(in, line))
    {
        if (line[0] == '#')
        {
            group = line.substr(1);
            outGroups[group] = vector<Student>();
        }
        else
        {
            if (crStudent.Name.empty())
            {
                crStudent.Name = line;
            }
            else if (crStudent.Year == 0)
            {
                crStudent.Year = stoi(line);
            }
            else if (record_size == 0)
            {
                record_size = stoi(line);
            }
            else if (subject.empty())
            {
                subject = line;
            }
            else
            {
                Score crScore = static_cast<Score>(stoi(line));
                crStudent.RecordBook[subject] = crScore;
                subject.clear();
                record_size--;
                if (record_size == 0)
                {
                    outGroups[group].push_back(crStudent);
                    crStudent = Student();
                }
            }
        }
    }
    in.close()
}
