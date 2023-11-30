#include <iostream>

using namespace std;

void read() {
    int n;  cin >> n;
    if(n & 1) cout << "Lihwy\n";
    else cout << "FireGhost\n";
}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--) {
        read();
    }

    return 0;
}
