#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int n, type, val;
   map<string, int>::iterator ind;
   string key;
   map<string, int> m;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      cin >> type >> key;
      // cout << type << key;
      switch (type)
      {
      case 1:
         cin >> val;
         ind = m.find(key);
         if (ind == m.end())
         {
            m.insert(make_pair(key, val));
         }
         else
         {
            m[key] += val;
         }
         break;
      case 2:
         m.erase(key);
         break;
      case 3:
         cout << m[key] << endl;
         break;
      default:
         return 1;
      }
   }
   return 0;
}
