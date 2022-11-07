#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int T;
   cin >> T;
   cout << setiosflags(ios::uppercase);
   cout << setw(0xf) << internal;
   while (T--)
   {
      double A;
      cin >> A;
      double B;
      cin >> B;
      double C;
      cin >> C;
      int tmpA = A;
      cout << nouppercase << showbase << hex << left << (long)A << endl;
      // printf("0x%x\n", int(A));
      // cout << setw(15) << setprecision(2) << right << showpos << setfill('_') << fixed << B << noshowpos << endl;
      cout << setw(15) << setprecision(2) << setfill('_') << right << showpos << fixed << B << noshowpos << endl;
      //
      cout << uppercase << scientific << setprecision(9) << C << endl;
      // printf("%.9E\n", C);
   }
   return 0;
}

// 0x3bf
// ________+199.25
// 4.708880000E+02
// 0x4a
// ________+802.75
// 3.962950000E+02
// 0x182
