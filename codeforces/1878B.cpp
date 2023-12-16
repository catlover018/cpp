#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

long long sequence[maxn];

void readInput() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cout << sequence[i] << ' ';
    cout << '\n';
}

void generateSequence() {
    int n = 2e5;
    sequence[1] = (rand() % 10) + 1;
    sequence[2] = sequence[1] + (rand() % 10) + 1;

    for (int i = 3; i <= n; ++i) {
        sequence[i] = sequence[i - 1] + ((rand() % 10) + 1);
        while (sequence[i] * 3 % (sequence[i - 1] + sequence[i - 2]) == 0) {
            sequence[i] = sequence[i - 1] + ((rand() % 10) + 1);
        }
    }
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCases;
    cin >> testCases;

    generateSequence();

    while (testCases-- > 0)
        readInput();

    return 0;
}
