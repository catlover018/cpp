#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e6;

int cnt[maxN];
pair<int, int> query[maxN + 5];

void Read(int &x){
    x = 0;
    char C = getchar();
    while(C>'9' || C<'0')
        C = getchar();
    while(C>='0' && C<='9'){
        x = x*10 + C - 48;
        C = getchar();
    }
}

void clear() {
    for(int i = 0; i <= 1e5; ++i) cnt[i] = 0;
}

void read() {
    int n;  Read(n);   bool check = true;
    clear();
    while(n--) {
        int type, x;    Read(type); Read(x);
        if(type == 1) {
            ++cnt[x];
        } else {
            if(cnt[x] > 0) --cnt[x];
            else if(cnt[0] > 0) --cnt[0];
            else {
                check = false;
            }
        }
    }
    cout << (check ? "YES" : "NO") << '\n';
}

void sol() {
    int testcase;   cin >> testcase;
    while(testcase--) read();
}

int main() {

    sol();

    return 0;
}
