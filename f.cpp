#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        char password[20];
        cin >> password;
        int j = 0;
        while (password[j] != 0) {
            if (password[j] >= '0' && password[j] <= '9') {
                ++j;
                continue;
            }
            cout << password[j];
            ++j;
        }
        cout << endl;
    }
}

/*
It is said that the famous Somali Pirates hate digits. So their QQ passwords never contain any digit. Given some lines of candidate passwords, you are asked to delete all the digits in the passwords and print other characters in their original order. So the Somali Pirates can use them as their QQ passwords^^

Input

There are multiple test cases. The first line of input is an integer T (T <= 10) indicating the number of test cases.

Each case contains a line indicating a candidate password. The length of the password is between 1 and 20, inclusive. Besides, the password consists of only digits and English letters.

Output

For each candidate password, delete all the digits and print the remaining characters in a line.

Sample Input

2
BeatLA123
1plus1equals1
Sample Output

BeatLA
plusequals
*/