/**
 * @author: Lam Nguyen
 *
 * Chapter 3: Backtrack
 *
 * @description:
 * This program will list all subsets of k elements
 * of {1,2,...,n}.
 *
 * @idea:
 * - x[0..n-1] with x[i] belongs to S
 * - x[0] < x[1] < x[2] < ... < x[k]
 *      x[k] <= n
 *      x[k-1] <= x[k]-1 <= n-1
 *      ...
 *      x[0] <= n-k
 * -> x[i-1] + 1 <= x[i] <= n-k+i (1 <= i <= k)
 *
 * @input: 4 3
 * @output:
 * {1, 2, 3}
 * {1, 2, 4}
 * {1, 3, 4}
 * {2, 3, 4}
 */

#include <bits/stdc++.h>
using namespace std;

// index 1 -> k
void print(int x[], int k) {
    cout << "{";
    for (int i = 1; i < k; i++) {
        cout << x[i] << ", ";
    }
    cout << x[k] << "}" << '\n';
}

void attempt(int x[], int n, int k, int i) {
    // index 1 -> k
    if (i == k+1) {
        print(x, k);
        return;
    }
    for (int j = x[i-1]+1; j <= n-k+i; j++) {
        x[i] = j;
        attempt(x, n, k, i+1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int x[k+1];
    x[0] = 0;
    for (int i = 1; i <= k; i++) x[i] = i;
    attempt(x, n, k, 1);
}
