// author: Lam Nguyen
// permutation without replacement

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int x[MAX];
bool c[MAX];

void print(int k) {
    for (int i = 0; i < k; i++) cout << x[i] << ' ';
    cout << '\n';
}

void attempt(int n, int k, int i) {
    if (i == k) {
        print(k);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (c[j]) {
            x[i] = j;
            c[j] = false;
            attempt(n, k, i+1);
            c[j] = true;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) c[i] = true;
    attempt(n, k, 0);
}

