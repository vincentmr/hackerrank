#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s)
{
   bool arr[128], ispangram{true};
   int i;
   for (i = 0; i < 128; i++)
   {
      arr[i] = false;
   }
   for (i = 0; i < s.size(); i++)
   {
      arr[int(s[i])] = true;
   }
   for (i = 65; i < 91; i++)
   {
      if (!arr[i] && !arr[i + 32])
      {
         ispangram = false;
      }
   }
   if (ispangram)
   {
      std::cout << std::string("pangram") << std::endl;
      return std::string("pangram");
   }
   else
   {
      std::cout << std::string("not pangram") << std::endl;
      return std::string("not pangram");
   }
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string s;
   getline(cin, s);

   string result = pangrams(s);

   fout << result << "\n";

   fout.close();

   return 0;
}
