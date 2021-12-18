#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int n, k;
        cin >> n >> k;
        int positive[10001], negative[10001];
        int pSize = 0, nSize = 0;
        for (int i = 0; i < 10001; ++i) {
            positive[i] = negative[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            if (v > 0) {
                positive[++pSize] = v;
                int j = pSize;
                while (j > 1 && positive[j] > positive[j / 2]) {
                    int t = positive[j];
                    positive[j] = positive[j / 2];
                    positive[j / 2] = t;
                    j /= 2;
                }
            } 
            if (v < 0) {
                negative[++nSize] = -v;
                int j = nSize;
                while (j > 1 && negative[j] > negative[j / 2]) {
                    int t = negative[j];
                    negative[j] = negative[j / 2];
                    negative[j / 2] = t;
                    j /= 2;
                }
            }
        }
        // for (int i = 1; i <= pSize; ++i) {
        //     cout << positive[i] << " ";
        // }
        // cout << endl;
        int count = 0;
        while (pSize >= k) {
            count += positive[1] * 2;
            for (int i = 0; i < k; ++ i) {
                positive[1] = positive[pSize];
                positive[pSize--] = 0;
                int j = 1;
                if (2*j > pSize) { continue; }
                while (positive[j] < positive[2*j] || (2*j + 1 <= pSize && positive[j] < positive[2*j + 1])) {
                    if (2*j + 1 > pSize || positive[2*j] > positive[2*j + 1]) {
                        int t = positive[j];
                        positive[j] = positive[2*j];
                        positive[2*j] = t;
                        j *= 2;
                    } else {
                        int t = positive[j];
                        positive[j] = positive[2*j + 1];
                        positive[2*j + 1] = t;
                        j = 2 * j + 1;
                    }
                    if (2*j > pSize) {
                        break;
                    }
                }
            }
        }
        // for (int i = 1; i <= pSize; ++i) {
        //     cout << positive[i] << " ";
        // }
        // cout << endl;
        while (nSize >= k) {
            count += negative[1] * 2;
            for (int i = 0; i < k; ++ i) {
                negative[1] = negative[nSize];
                negative[nSize--] = 0;
                int j = 1;
                if (2*j > nSize) { continue; }
                while (negative[j] < negative[2*j] || (2*j + 1 <= nSize && negative[j] < negative[2*j + 1])) {
                    if (2*j + 1 > nSize || negative[2*j] > negative[2*j + 1]) {
                        int t = negative[j];
                        negative[j] = negative[2*j];
                        negative[2*j] = t;
                        j *= 2;
                    } else {
                        int t = negative[j];
                        negative[j] = negative[2*j + 1];
                        negative[2*j + 1] = t;
                        j = 2 * j + 1;
                    }
                    if (2*j > nSize) {
                        break;
                    }
                }
            }

        }
        if (pSize == 0 || nSize == 0) {
            if (pSize == 0) {
                count += negative[1];
            } else {
                count += positive[1];
            }
        } else  {
            count += positive[1] + negative[1];
            if (positive[1] > negative[1]) {
                count += negative[1];
            } else {
                count += positive[1];
            } 
        }

        cout << count << endl;
    }
}
/*
$N$ letters have just arrived at the post office positioned at $x = 0$, and the $i$-th letter should be posted to position $x = a_i$. BaoBao, our beloved postman, will start his work from the post office and deliver all these letters by himself.

Unfortunately, BaoBao's backpack can only hold at most $K$ letters each time (which means that if he wants to deliver some letter not in his backpack, he will have to go back to the post office and fetch it), so he may not be able to deliver all $N$ letters in one go. Please note that BaoBao cannot temporarily drop a letter outside the post office and pick it back afterward.

What's the minimum distance BaoBao has to travel to deliver all $N$ letters?

It's NOT necessary that BaoBao ends his delivery in the post office.

Input

There are multiple test cases. The first line of the input contains an integer $T$, indicating the number of test cases. For each test case:

The first line contains two integers $N$ and $K$ ($1 \le K \le N \le 10^5$), indicating the total number of letters and the capacity of the backpack.

The second line contains $N$ integers $a_1, a_2, \dots, a_N$ ($-10^9 \le a_i \le 10^9$), indicating the destination of each letter.

It's guaranteed that the sum of $N$ over all test cases will not exceed $10^6$.

Output

For each test case output one line containing one integer, indicating the minimum distance BaoBao has to travel to deliver all the letters, starting from the post office at $x = 0$.

Sample Input

2
5 3
-1 -2 3 -4 -5
6 3
1 0 -2 -1 1 2
Sample Output

13
6
Hint

For the first sample test case, BaoBao can first deliver the 1st and the 3rd letter (go to $x = 3$, then to $x = -1$, then to the post office), then deliver the 2nd, the 4th and the 5th letter (go to $x = -2$, then to $x = -4$, then to $x = -5$), and ends his delivery at $x = -5$.
*/