#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        
    }
}

/*
Now we have a tree and some queries to deal with. Every node in the tree has a value on it. For one node A, we want to know the largest three values in all the nodes of the subtree whose root is node A. Node 0 is root of the tree, except it, all other nodes have a parent node.

Input

There are several test cases. Each test case begins with a line contains one integer n(1 ≤ n ≤ 10000), which indicates the number of the node in the tree. The second line contains one integer v[0], the value on the root. Then for the following n - 1 lines(from the 3rd line to the (n + 1)th line), let i + 2 be the line number, then line i + 2 contains two integers parent and v[i], here parent is node i's parent node, v[i] is the value on node i. Here 0 ≤ v[i] ≤ 1000000. Then the next line contains an integer m(1 ≤ m ≤ 10000), which indicates the number of queries. Following m lines, each line contains one integer q, 0 ≤ q < n, it meas a query on node q.

Output

For each test case, output m lines, each line contains one or three integers. If the query asked for a node that has less than three nodes in the subtree, output a "-1"; otherwise, output the largest three values in the subtree, from larger to smaller.

Sample Input

5
1
0 10
0 5
2 7
2 8
5
0
1
2
3
4
Sample Output

10 8 7
-1
8 7 5
-1
-1
*/