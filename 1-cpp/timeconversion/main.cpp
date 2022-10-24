#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string p, t;
    int l;
    int hour, i;

    l = s.size();
    p = s.substr(l - 2, 2);
    i = s.find_first_of(":");
    hour = std::stoi(s.substr(0, i));
    if (hour == 12)
        hour = 0;
    if (p == "PM")
        hour += 12;
    t = std::to_string(hour);
    if (t.size() == 1)
        t = "0" + t;
    t += s.substr(i, l - 2);
    return t;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
