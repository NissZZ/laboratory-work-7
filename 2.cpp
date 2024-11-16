#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Book
{
    string Author;
    string Title;
    int Year;
};

void saveToFile(const string& filename, const vector<Book>& data)
{
    ofstream out;
    out.open(filename);
    for (int i = 0; i < data.size(); ++i)
    {
        out << data[i].Author << endl;
        out << data[i].Title << endl;
        out << data[i].Year << endl;
    }
    out.close();
}

void loadFromFile(const string& filename, vector<Book>& outData)
{
    ifstream in;
    in.open(filename);
    string line;
    int cnt = 0;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (cnt == 0 || cnt % 3 == 0)
            {
                outData.push_back(Book());
                outData[cnt].Author = line;
            }
            else if (cnt == 1 || cnt % 3 == 1)
            {
                outData[cnt].Title = line;
            }
            else
            {
                outData[cnt].Year = stoi(line);
            }
            ++cnt;
        }
    }
    in.close();
}
