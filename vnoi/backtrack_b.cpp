#include <iostream>
#include <cstring>
using namespace std;

long long countTime = 0;
bool checkFirst = false;

bool checkTrace[40][100][100];
string Trace[40][100][100];

void Move(int n, char source, char target, char temp, string& str) {

    if (n < 1) return;
    if (n == 1) {
        countTime += 1;
        str = str + source + target + "\n";
    }
    else {
        string str_temp1 = "";
        if (checkTrace[n - 1][source][temp] == false) {
            Trace[n - 1][source][temp] = "";
            Move(n - 1, source, temp, target, str_temp1);
            Trace[n - 1][source][temp] = str_temp1;
            checkTrace[n - 1][source][temp] = true;
        }
        else {
            str_temp1 = Trace[n - 1][source][temp];
            countTime += str_temp1.length() / 3;
        }

        string str_temp2 = "";
        if (checkTrace[1][source][target] == false) {
            Trace[1][source][target] = "";
            Move(1, source, target, temp, str_temp2);
            Trace[1][source][target] = str_temp2;
            checkTrace[1][source][target] = true;
        }
        else {
            str_temp2 = Trace[1][source][target];
            countTime += str_temp2.length() / 3;
        }

        string str_temp3 = "";
        if (checkTrace[n - 1][temp][target] == false) {
            Trace[n - 1][temp][target] = "";
            Move(n - 1, temp, target, source, str_temp3);
            Trace[n - 1][temp][target] = str_temp3;
            checkTrace[n - 1][temp][target] = true;
        }
        else {
            str_temp3 = Trace[n - 1][temp][target];
            countTime += str_temp3.length() / 3;
        }

        // last processs
        if (str.length() > 0 && str_temp1[0] == str[str.length() - 2]) {
            str[str.length() - 2] = str_temp1[1];
            str_temp1.erase(0, 3);
            countTime--;
            if (str[str.length() - 2] == str[str.length() - 3]) {
                str.erase(str.length() - 3, 3);
                countTime--;
            }
        }

        if (str_temp1.length() > 0 && str_temp2[0] == str_temp1[str_temp1.length() - 2]) {
            str_temp1[str_temp1.length() - 2] = str_temp2[1];
            str_temp2.erase(0, 3);
            countTime--;
            if (str_temp1[str_temp1.length() - 2] == str_temp1[str_temp1.length() - 3]) {
                str_temp1.erase(str_temp1.length() - 3, 3);
                countTime--;
              }
            }

            if (str_temp2.length() > 0 && str_temp3[0] == str_temp2[str_temp2.length() - 2]) {
              str_temp2[str_temp2.length() - 2] = str_temp3[1];
              str_temp3.erase(0, 3);
              countTime--;
              if (str_temp2[str_temp2.length() - 2] == str_temp2[str_temp2.length() - 3]) {
                str_temp2.erase(str_temp2.length() - 3, 3);
                countTime--;
              }
            }

            str = str + str_temp1 + str_temp2 + str_temp3;
          }
        }

void HanoiTower(int* arrX, int i, int* findX, string& str) {
        // @check
    if (arrX[i] == -1) return;
    int getX = arrX[i];
    int positionX = findX[getX];

    if (positionX == 1) {
        Move(getX - 1, 'C', 'B', 'A', str);
        Move(1, 'A', 'C', 'B', str);
        Move(getX - 1, 'B', 'C', 'A', str);
    }
    else if (positionX == 2) {
        Move(getX - 1, 'C', 'A', 'B', str);
        Move(1, 'B', 'C', 'A', str);
        Move(getX - 1, 'A', 'C', 'B', str);
    }

    if (str.length() >= 6 && checkFirst == false) {
        checkFirst = true;
            if (str[1] == str[3]) {
            if (str[0] != str[4]) {
                str.erase(1, 3);
                countTime -= 1;
            }
            else {
                str.erase(0, 6);
                countTime -= 2;
            }
        }
    }

    HanoiTower(arrX, i + 1, findX, str);
}
        // @helper method
    void showArray(int* arr, int n) {
        for (int i = 0; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

int main() {
    int n;
    cin >> n;
    cin.ignore();

    char str[100];
    cin.getline(str, 100);

    int column1[100] = { 0 };
    int a = -1;

    int column2[100] = { 0 };
    int b = -1;

    int column3[100] = { 0 };
    int c = -1;


    // @set column
    for (int i = strlen(str) - 1; i >= 0; i--) {
    if (str[i] == 'A') {
        column1[++a] = i + 1;
    }

    if (str[i] == 'B') {
        column2[++b] = i + 1;
    }

    if (str[i] == 'C') {
        column3[++c] = i + 1;
        }
    }

    int arrX[100] = { 0 };
    int d = -1;

    int i = c;
    int num = 1;

    // @getX
    while (num <= n) {
        if (column3[i] == num) {
            num++;
            if (i > 0) i--;
        }
        else {
            arrX[++d] = num;
            num++;
        }
    }
    // end of arrX
    arrX[++d] = -1;

    // @findX
    int findX[100] = { 0 };
    int f = 0;

    int temp1 = a;
    int temp2 = b;
    int temp3 = 0;
    for (int i = 0; i <= d - 1; i++) {
        if (arrX[temp3] == column1[temp1]) {
            findX[arrX[temp3]] = 1;
            temp3++;
            temp1--;
        }
        else {
            findX[arrX[temp3]] = 2;
            temp3++;
            temp2--;
        }
    }

    // process
    string strTemp = "";

    HanoiTower(arrX, 0, findX, strTemp);
    cout << countTime << endl;
    cout << strTemp;

    return 0;
}
