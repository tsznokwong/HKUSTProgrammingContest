#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int a) {

    int sq = (int) sqrt((double) a);
    // cout << "A" << sq << a << endl;
    for (int i = 2; i <= sq; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return a != 1;
}

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int N, Q;
        cin >> N >> Q;
        int seq[100000];
        for (int i = 0; i < N; ++i) {
            cin >> seq[i];
        }
        // for (int i = 0; i < N; ++i) {
        //     cout << seq[i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < Q; ++i) {
            char instruction;
            int v, l, a, r;
            int count = 0;
            cin >> instruction;
            switch (instruction) {
            case 'A':
                cin >> v >> l;
                ++N;
                for (int i = N; i > l - 1; --i) {
                    seq[i] = seq[i-1];
                }
                seq[l-1] = v;
                break;
            case 'Q':
                cin >> l >> r;
                for (int i = l - 1; i <= r - 1; ++i) {
                    if (isPrime(seq[i])) {
                        ++count;
                    }
                }
                cout << count << endl;
                break;
            case 'R':
                cin >> a >> l >> r;
                for (int i = l - 1; i <= r - 1; ++i) {
                    seq[i] = a;
                }
                break;
            }

            for (int i = 0; i < N; ++i) {
                cout << seq[i] << " ";
            }
            cout << endl;
        }
    }
}

/*
You are given a simple task. Given a sequence A[i] with N numbers. You have to perform Q operations on the given sequence.

Here are the operations:

A v l, add the value v to element with index l.(1<=V<=1000)
R a l r, replace all the elements of sequence with index i(l<=i<= r) with a(1<=a<=10^6) .
Q l r, print the number of elements with index i(l<=i<=r) and A[i] is a prime number
Note that no number in sequence ever will exceed 10^7.

Input

The first line is a signer integer T which is the number of test cases.

For each test case, The first line contains two numbers N and Q (1 <= N, Q <= 100000) - the number of elements in sequence and the number of queries.

The second line contains N numbers - the elements of the sequence.

In next Q lines, each line contains an operation to be performed on the sequence.

Output

For each test case and each query,print the answer in one line.

Sample Input

1
5 10
1 2 3 4 5
A 3 1      
Q 1 3
R 5 2 4
A 1 1
Q 1 1
Q 1 2
Q 1 4
A 3 5
Q 5 5
Q 1 5
Sample Output

2
1
2
4
0
4
*/