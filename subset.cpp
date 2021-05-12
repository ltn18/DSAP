/**
 * @author: Lam Nguyen
 *
 * Chapter 2: Generation
 *
 * @description:
 * This program will list all subsets of k elements
 * of {1,2,...,n}.
 *
 * @idea:
 * - Find the first element that has not reached upper bound n-k+i
 * - Increase x[i] by 1
 * - Set all elements after x[i] equals to lower bound
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

void print(int s[], int k) {
    cout << "{";
    for (int i = 0; i < k-1; i++) {
        cout << s[i] << ", ";
    }
    cout << s[k-1] << "}" << '\n';
}

bool end(int s[], int n, int k) {
    for (int i = 0; i < k; i++) {
        if (s[i] != n-k+i+1) return false;
    }
    return true;
}

void gen(int n, int k) {
    if (n == 0 || k == 0) return;

    int s[k];
    for (int i = 0; i < k; i++) s[i] = i+1;
    print(s, k);
    while(!end(s, n, k)) {
        int idx = k - 1;
        while (idx >= 0) {
            if (s[idx] < n - k + idx + 1) {
                s[idx]++;
                for (int i = idx + 1; i < n; i++) s[i] = s[i - 1] + 1;
                print(s, k);
            }
            idx--;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    gen(n, k);
}
