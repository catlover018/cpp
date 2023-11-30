#include <iostream>

using namespace std;

int main() {
    string s;   cin >> s;
    if(s == "I") cout << "am";
    else if(s == "He" || s == "She" || s == "It") cout << "is";
    else if(s == "They" || s == "We" || s == "You") cout << "are";
    else cout << "is";

    return 0;
}
