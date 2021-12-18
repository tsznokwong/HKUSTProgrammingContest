#include <iostream>
#include <cmath>

using namespace std;

int computed[2001][2001];

bool isPrime(int a) {
    int sq = (int) sqrt((double) a);
    for (int i = 2; i <= sq; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return a != 1;
}

int solve(int value, int index) {
    // cout << value << " " << index << endl;
    if (computed[value][index]) {
        return computed[value][index];
    }
    if (index == 1 || value == 1) {
        computed[value][index] = 1;
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= value; ++i) {
        if (value % i == 0) {      
            count = (count + solve(i, index - 1)) % 1000000007;
        }
    }
    count = (count + solve(value - 1, index)) % 1000000007;
    computed[value][index] = count;
    return count;
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < 2001; ++i) {
        for (int j = 0; j < 2001; ++j) {
            computed[i][j] = 0;
        }
    }
    for (int i = 0; i < testcases; ++i) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    // for (int i = 0; i < 97; ++i) {
        for (int j = 0; j < 2001; ++j) {
            cout << computed[97][j] << " ";
        }
    // }
}

/*
A sequence of \(k\) integers \(b_1, b_2, \dots, b_k\) (\(1 \le b_1 \le b_2 \le ... \le b_k \le n\)) is called a happy sequence if each number divides (without a remainder) the next number in the sequence. More formally, we can say \(b_i | b_{i+1}\) for all \(1 \le i \le k-1\), or we can say \(b_{i+1} \text{ mod } b_i = 0\) for all \(1 \le i \le k-1\).

Given \(n\) and \(m\), find the number of happy sequences of length \(m\). Two sequences \(x_1, x_2, \dots, x_m\) and \(y_1, y_2, \dots, y_m\) are different, if and only if there exists an \(i\) such that \(1 \le i \le m\) and \(x_i \ne y_i\).

As the answer can be rather large print it modulo \(1000000007\) (\(10^9 + 7\)).

Input

There are multiple test cases. The first line of the input contains an integer \(T\) (about 50), indicating the number of test cases. For each test case:

The first and only line contains two integers \(n\) and \(m\) (\(1 \le n, m \le 2000\)), indicating the upper limit of the elements in the sequence and the length of the sequence.

Output

For each case output a single integer, indicating the number of happy sequences of length \(m\) modulo \(10^9+7\)

Sample Input

1
3 2
Sample Output

5
Hint

In the sample test case, the happy sequences are: \([1, 1]\), \([2, 2]\), \([3, 3]\), \([1, 2]\), \([1, 3]\).
*/