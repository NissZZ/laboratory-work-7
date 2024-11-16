#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void saveToFile(const string& filename, const vector<string>& data)
{
   ofstream out;
   out.open(filename);
   for (int i = 0; i < data.size(); i++)
   {
      out << data[i] << endl;
   }
   out.close();
}

void loadFromFile(const string& filename, vector<string>& outData)
{
   ifstream in;
   in.open(filename);
   string line;
   if (in.is_open())
   {
      while (getline(in, line))
      {
         outData.push_back(line);
      }
   }
   in.close();
}
