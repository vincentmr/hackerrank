#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void get_attr_simple(string line, string attr)
{
   size_t found{};
   int lb{}, ub{};
   string stmp;

   found = line.find(attr);
   if (found == std::string::npos)
   {
      cout << "Not Found!\n";
   }
   else
   {
      stmp = line.substr(found, line.size());
      found = stmp.find('"');
      stmp = stmp.substr(found + 1, stmp.size());
      found = stmp.find('"');
      stmp = stmp.substr(0, found);
      cout << stmp << '\n';
   }
}

void query_tag_simple(vector<string> attrs, string query)
{
   int found{};
   string tag, attr;
   int level{0};
   found = query.find("~");
   if (found != std::string::npos)
   {
      tag = query.substr(0, found - 1);
      attr = query.substr(found + 1, query.size() - 1);
   }
   for (int i = 0; i < attrs.size(); i++)
   {

      found = attrs[i].find("</");
      if (found != std::string::npos)
      {
         level += 1;
      }
      else
      {
         level -= 1;
      }
      // cout << level << '\n';

      found = attrs[i].find(tag);
      if (found != std::string::npos)
      {
         if (level != 1)
         {
            cout << "Not Found!\n";
            return;
         }
         get_attr_simple(attrs[i], attr);
         return;
      }
   }
}

void query_tag(vector<string> attrs, string query)
{
   if (query.find(".") == std::string::npos)
   {
      query_tag_simple(attrs, query);
   }
   else
   {
      int i, j;
      int lb, ub;
      int found{};
      int level{0};
      string maintag;

      found = query.find(".");
      maintag = query.substr(0, found);
      // cout << maintag << endl;
      for (int i = 0; i < attrs.size(); i++)
      {
         found = attrs[i].find("</");
         if (found != std::string::npos)
         {
            level += 1;
         }
         else
         {
            level -= 1;
         }
         // cout << level << '\n';
         found = attrs[i].find(maintag);
         if (found != std::string::npos)
         {
            if (level != 1)
            {
               cout << "Not Found!\n";
               return;
            }
            lb = i;
            break;
         }
      }
      maintag = "/" + maintag;
      for (int i = lb + 1; i < attrs.size(); i++)
      {
         found = attrs[i].find(maintag);
         if (found != std::string::npos)
         {
            ub = i;
            break;
         }
      }
      vector<string> subattrs(&attrs[lb + 1], &attrs[ub - 1]);
      found = query.find(".");
      query_tag(subattrs, query.substr(found + 1, query.size() - 1));
      return;
   }
   return;
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

string read_one_line()
{
   string strtmp;
   getline(cin, strtmp);
   return strtmp;
}

vector<string> readnlines(int n)
{
   vector<string> nlines;
   nlines.reserve(n);
   for (int i = 0; i < n; i++)
   {
      nlines.push_back(read_one_line());
   }
   return nlines;
}

int main()
{
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int n, q;
   int i{0};

   string strtmp;
   vector<string> nq;
   getline(cin, strtmp);
   nq = split(ltrim(rtrim(strtmp)));
   n = stoi(nq[0]);
   q = stoi(nq[1]);

   vector<string> at;
   vector<string> qr;

   at = readnlines(n);
   qr = readnlines(q);

   for (int i = 0; i < q; i++)
   {
      query_tag(at, qr[i]);
   }

   return 0;
}
