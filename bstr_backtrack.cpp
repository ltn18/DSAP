/**
 * @author: Lam Nguyen
 *
 * Chapter 3: Backtrack
 *
 * Binary string of length n is a binary representation of
 * p(x) in [0, 2^n-1]. The number of binary strings = 2^n.
 *
 * @description:
 * This program will list all binary string representations
 * of numbers in range [0, 2^n-1].
 *
 * @idea:
 * - Use backtrack to try different values for x[i] -> x[i+1]
 *
 * @input: 3
 * @output:
 * 000
 * 001
 * 010
 * 011
 * 100
 * 101
 * 110
 * 111
 */

#include <bits/stdc++.h>
using namespace std;

void print(int x[], int n) {
    for (int i = 0; i < n; i++) cout << x[i] << " ";
    cout << '\n';
}

void attempt(int x[], int n, int i) {
    if (i == n) {
        print(x, n);
        return;
    }
    for (int j = 0; j < 2; j++) {
        x[i] = j; // try x[i] = 0 and 1
        attempt(x, n, i+1); // push to stack
    }
}

int main() {
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) x[i] = 0;
    attempt(x, n, 0);
}
