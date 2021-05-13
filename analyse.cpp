// author: Lam Nguyen
// number partition: split a number into sum of integers

/**
 * @idea:
    t[i] = sum of x[1] ... x[i]
    * condition for not stating a case twice: x[i-1] <= x[i]
    we have t[i+1] <= n
    -> t[i-1] + x[i] + x[i+1] <= n
    -> x[i] + x[i+1] <= n - t[i-1]
    -> x[i] <= (n - t[i-1]) / 2

    we solve this problem with elements from 1->n
    x[0] = 1 and t[0] = 0
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int x[MAXN], t[MAXN];

void print(int x[], int n, int k) {
    cout << n << " = ";
    for (int i = 1; i <= k-1; i++) cout << x[i] << " + ";
    cout << x[k] << '\n';
}

void attempt(int x[], int n, int i) {
    for (int j = x[i-1]; j <= (n - t[i-1]) / 2; j++) {
        x[i] = j;
        t[i] = t[i-1] + j;
        attempt(x, n, i+1);
    }
    x[i] = n - t[i-1]; // x[i] is last element then it has to be n - t[i-1]
    print(x, n, i);
}

int main() {
    int n;
    cin >> n;
    x[0] = 1; t[0] = 0;
    attempt(x, n, 1);
}

