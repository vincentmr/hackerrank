#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'towerBreakers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

bool next_move(int n, int *towers)
{
   for (int i = 0; i < n; i++)
   {
      if (towers[i] == 1)
         continue;
      for (int j = towers[i] - 1; j > 0; j--)
      {
         // std::cout << i << " " << j << std::endl;
         // std::cout << towers[i] % (towers[i] - j) << std::endl;
         if ((towers[i] % (towers[i] - j)) == 0)
         {
            towers[i] -= j;
            return false;
         }
      }
   }
   return true;
}

void print_vec(int n, int *vec)
{
   for (int i = 0; i < n; i++)
   {
      std::cout << vec[i] << " ";
   }
   std::cout << std::endl;
}

int towerBreakers(int n, int m)
{
   bool done{false};
   int towers[n];
   int player;

   if (m == 1 || (n % 2) == 0)
   {
      return 2;
   }
   else
   {
      return 1;
   }
   for (int i = 0; i < n; i++)
   {
      towers[i] = m;
   }
   player = 2;
   done = next_move(n, towers);
   // std::cout << done << std::endl;
   // print_vec(n, towers);
   while (!done)
   {
      player += 1;
      done = next_move(n, towers);
      // print_vec(n, towers);
   }
   if (player % 2 == 0)
   {
      std::cout << 2 << " wins" << std::endl;
      return 2;
   }
   else
   {
      std::cout << 1 << " wins" << std::endl;
      return 1;
   }
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string t_temp;
   getline(cin, t_temp);

   int t = stoi(ltrim(rtrim(t_temp)));

   for (int t_itr = 0; t_itr < t; t_itr++)
   {
      string first_multiple_input_temp;
      getline(cin, first_multiple_input_temp);

      vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

      int n = stoi(first_multiple_input[0]);

      int m = stoi(first_multiple_input[1]);

      int result = towerBreakers(n, m);

      fout << result << "\n";
   }

   fout.close();

   return 0;
}

string ltrim(const string &str)
{
   string s(str);

   s.erase(
       s.begin(),
       find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

   return s;
}

string rtrim(const string &str)
{
   string s(str);

   s.erase(
       find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
       s.end());

   return s;
}

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
