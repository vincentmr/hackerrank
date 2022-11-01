#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    string c;
    std::cin >> a;
    std::cin >> b;
    std::cout << a.size() << " " << b.size() << '\n';
    std::cout << a + b << '\n';
    c = b.front() + a.substr(1, a.size());
    std::cout << c << " ";
    c = a.front() + b.substr(1, a.size());
    std::cout << c << '\n';
    return 0;
}