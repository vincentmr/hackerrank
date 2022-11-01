#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int m, n;
   std::cin >> m >> n;
   vector<vector<int>> dat{};
   dat.reserve(m);
   int q0, q1;
   int tmp{};
   for (int i = 0; i < m; i++)
   {
      std::cin >> tmp;
      dat[i].reserve(tmp);
      for (int j = 0; j < dat[i].size(); j++)
      {
         std::cin >> tmp;
         dat[i].push_back(tmp);
      }
   }
   for (int i = 0; i < n; i++)
   {
      std::cin >> q0 >> q1;
      std::cout << dat[q0][q1] << std::endl;
   }

   return 0;
}