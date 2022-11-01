#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s;
   int n, i{0};
   cin >> n;
   while (getline(cin, s) && i < n)
   {
      std::cout << s << '\n';
      i++;
   }
   return 0;
}