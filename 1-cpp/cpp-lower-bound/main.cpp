#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::pair<int, int> mypair;
bool comparator(const mypair &l, const mypair &r)
{
   return l.first < r.first;
}

void sort_array(int q, const int *qr, int *qrp, int *iqr)
{
   vector<mypair> pair;
   for (int i = 0; i < q; i++)
   {
      pair.push_back({qr[i], i});
   }
   sort(pair.begin(), pair.end());
   for (int i = 0; i < q; i++)
   {
      qrp[i] = pair[i].first;
      iqr[i] = pair[i].second;
   }
}

void find_entry_sort(int n, const int *ar, int q, const int *qr, int *res)
{
   int qtmp, lasti{0};
   int i;
   for (int j = 0; j < q; j++)
   {
      qtmp = qr[j];
      for (i = lasti; i < n; i++)
      {
         if (ar[i] == qtmp)
         {
            res[j] = i + 1;
            lasti = i;
            break;
         }
         else if (ar[i] > qtmp)
         {
            res[j] = -(i + 1);
            lasti = i;
            break;
         }
      }
      if (i == n)
      {
         res[j] = -(n + 1);
         lasti = n;
      }
   }
   return;
}

void print_entry_sort(int q, const int *qrp)
{
   for (int i = 0; i < q; i++)
   {
      if (qrp[i] > 0)
      {
         printf("Yes %d\n", qrp[i]);
      }
      else
      {
         printf("No %d\n", -qrp[i]);
      }
   }
}

void find_entry(int n, const int *ar, int q, const int *qr)
{
   int qrp[q], iqr[q];
   sort_array(q, qr, qrp, iqr);
   int res[q];
   find_entry_sort(n, ar, q, qrp, res);
   for (int i = 0; i < q; i++)
   {
      qrp[iqr[i]] = res[i];
   }
   print_entry_sort(q, qrp);
}

int main()
{
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int q, n;
   cin >> n;
   int ar[n];
   int *p;
   p = ar;
   for (int i = 0; i < n; i++)
   {
      scanf("%d", p);
      p++;
   }
   cin >> q;
   int qr[q];
   p = qr;
   for (int i = 0; i < q; i++)
   {
      scanf("%d", p);
      p++;
   }
   find_entry(n, ar, q, qr);
   return 0;
}
