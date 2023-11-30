#include <bits/stdc++.h>

using namespace std;

const int maxN = 60;

string A, B;

void read() {
  cin >> A >> B;
}

vector<char> v;

void sol() {
  int n = 0;
  for(char c : B) v.push_back(c);
  sort(v.begin(), v.end());
  string ans = "";
  bool ok = true;
  for(char c : A) {
    if(ok) {
      int p = upper_bound(v.begin(), v.end(), c)-v.begin();
    }
  }
}

int main() {

  return 0;
}
