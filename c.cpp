#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int v;
                cin >> v;
                if (v < A || v > B) {
                    ++count;
                }
            }
        } 
        if (A > B) {
            cout << "No Solution" << endl;
        } else {
            cout << count << endl;
        }
        
    }
}

/*
DreamGrid's birthday is coming. As his best friend, BaoBao is going to prepare a gift for him.

As we all know, BaoBao has a lot of matrices. This time he picks an integer matrix with \(n\) rows and \(m\) columns from his collection, but he thinks it's not pretty enough. On the one hand, he doesn't want to be stingy, but some integers in the matrix seem to be too small. On the other hand, he knows that DreamGrid is not good at algebra and hates large numbers, but some integers in the matrix seem to be too large and are not suitable for a gift to DreamGrid.

Based on the above consideration, BaoBao declares that a matrix is pretty, if the following conditions are satisfied:

For every integer \(a_{ij}\) in the matrix, \(a_{ij} \ge A\).
For every integer \(a_{ij}\) in the matrix, \(a_{ij} \le B\).
where \(a_{ij}\) is the integer located at the \(i\)-th row and the \(j\)-th column in the matrix, and \(A\) and \(B\) are two integers chosen by BaoBao.

Given the matrix BaoBao picks, along with the two integers \(A\) and \(B\), please help BaoBao change some integers in the matrix (BaoBao can change an integer in the matrix to any integer) so that the matrix becomes a pretty matrix. As changing integers in the matrix is tiring, please tell BaoBao the minimum number of integers in the matrix he has to change to make the matrix pretty.

Input

There are multiple test cases. The first line of input is an integer \(T\) (about 100), indicating the number of test cases. For each test case:

The first line contains four integers \(n\), \(m\), \(A\) and \(B\). (\(1 \le n, m \le 100, 1 \le A, B \le 10^5\)). Their meanings are described above.

For the next \(n\) lines, the \(i\)-th line contains \(m\) integers \(a_{i1}, a_{i2}, \dots, a_{im}\) (\(1 \le a_{ij} \le 10^5\)), representing the original matrix.

Output

For each test case output one line indicating the answer. If it's impossible to make the matrix pretty, print "No Solution" (without quotes) instead.

Sample Input

2
3 4 2 3
3 2 2 2
2 1 2 3
2 3 100 3
2 1 2 1
1
2
Sample Output

2
No Solution
*/