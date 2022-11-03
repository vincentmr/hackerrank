#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here

vector<string> split(const string &str)
{
   vector<string> tokens;

   string::size_type start = 0;
   string::size_type end = 0;

   while ((end = str.find(" ", start)) != string::npos)
   {
      tokens.push_back(str.substr(start, end - start));

      start = end + 1;
   }

   tokens.push_back(str.substr(start));

   return tokens;
}

class Student
{
private:
   vector<int> scores;

public:
   void input()
   {
      int stmp;
      while (scores.size() < 5)
      {
         cin >> stmp;
         scores.push_back(stmp);
         cout << stmp << " " << scores.size() << endl;
      }
   }
   int calculateTotalScore()
   {
      int s{0};
      for (int i = 0; i < scores.size(); i++)
      {
         s += scores[i];
      }
      return s;
   }
};

int main()
{
   int n; // number of students
   string str;
   cin >> n;

   Student *s = new Student[n]; // an array of n students

   for (int i = 0; i < n; i++)
   {
      s[i].input();
   }

   // calculate kristen's score
   int kristen_score = s[0].calculateTotalScore();

   // determine how many students scored higher than kristen
   int count = 0;
   for (int i = 1; i < n; i++)
   {
      int total = s[i].calculateTotalScore();
      if (total > kristen_score)
      {
         count++;
      }
   }

   // print result
   cout << count;

   return 0;
}
