#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int compare (const void * a, const void * b) {
  return ( *(double*)a - *(double*)b );
}

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int N;
        cin >> N;
        double seq[N];
        for (int i = 0; i < N; ++i) {
            cin >> seq[i];
        }
        qsort(seq, N, sizeof(double), compare);
        double result;
        if (N % 2) {
            result = seq[N / 2];
        } else {
            result = (seq[N / 2] + seq[N / 2 - 1]) / 2; 
        }
        printf("%.3lf\n", result);
    }
}

/*
A median is described as the numeric value separating the higher half of a list, from the lower half. The median of a finite list of numbers can be found by arranging all the elements from lowest value to highest value and picking the middle one. If there is an even number of elements, the median is then defined to be the mean of the two middle values. Now, could you write a program to help to find the median?

Input

There are multiple test cases. The first line of input is an integer T ≈ 100 indicating the number of test cases.

The first line of each test is an integer 0 < n < 500 indicating the number of elements. The second line consists of n numbers, the elements of the list, whose absolute values are smaller than 1,000,000.

Output

For each test case, output the median, with 3 decimal digits.

Sample Input

3
1
0.0
4
1.0 1000.3 100.2 10.1
5
2.0 3.0 5.0 7.0 11.0
Sample Output

0.000
55.150
5.000
References

http://en.wikipedia.org/wiki/Median
*/