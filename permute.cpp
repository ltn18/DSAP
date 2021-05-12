/**
 * @author: Lam Nguyen
 *
 * Chapter 2: Generation
 *
 * @description:
 * This program will list all permutation of {1,2,...,n}
 * in lexicographical order.
 *
 * @idea:
 * - Determine longest descending subset, find index i before that subset
 *   ( this means finding first i that satisfies x[i] < x[i+1] )
 * - If found i:
 *      * find the first index from end that satisfies x[idx] > x[i]
 *      * swap x[idx] and x[i]
 *      * Set all elements after idx to be ascending order
 * - If not found i -> this is final permutation
 *
 * @input: 3
 * @output:
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 */

#include <bits/stdc++.h>
using namespace  std;

void print(int x[], int n) {
    for (int i = 0; i < n; i++) cout << x[i] << " ";
    cout << '\n';
}

bool end(int x[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] != n-i) return false;
    }
    return true;
}

void swap(int x[], int i, int j) {
    int tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

void gen(int n) {
    if (n == 0) return;

    int x[n];
    for (int i = 0; i < n; i++) x[i] = i+1;
    print(x, n);
    while (!end(x, n)) {
        int idx = n-2;
        while (idx >= 0) {
            if (x[idx] < x[idx+1]) {
                int i = n-1;
                for (i; i > idx && x[i] < x[idx]; i--);
                swap(x, i, idx);
                int a = idx+1, b = n-1;
                while (a < b) {
                    swap(x, a, b);
                    a++;
                    b--;
                }
                print(x, n);
            }
            idx--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    gen(n);
}

