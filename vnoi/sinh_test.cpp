#include <bits/stdc++.h>

using namespace std;

const int Test = 100;
const string Name = "";

int Rand(int l, int r) {
    return (l + rand()) % r + 1;
}

int main() {
    srand(time(NULL));
    for(int iTest = 1; iTest <= Test; ++iTest) {
        ofstream inp((Name + ".inp").c_str());

        inp.close();
        system((Name + ".exe").c_str());
        system((Name + "_trau.exe").c_str());
        if(system(("fc " + Name + ".out " + Name + ".ans").c_str())) {
            cout << "Test: " << iTest << "Wrong!\n";
            return 0;
        }
        cout << "Test: " << iTest << "Correct!\n";
    }
    return 0;
}
