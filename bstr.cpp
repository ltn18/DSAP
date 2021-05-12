/**
 * @author: Lam Nguyen
 *
 * Chapter 2: Generation
 *
 * Binary string of length n is a binary representation of
 * p(x) in [0, 2^n-1]. The number of binary strings = 2^n.
 *
 * @description:
 * This program will list all binary string representations
 * of numbers in range [0, 2^n-1].
 *
 * @idea:
 * - Find the first '0' from end, replace that with '1'
 * - Replace all characters after that found '0' to be '0'
 * - If not found '0' -> no more generation
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

void gen(int n, string s) {
    if (n == 0) return;

    cout << s << '\n';

    for (int i = 0; i < n; i++) {
        int idx = n-1;
        while (idx >= 0) {
            if (s[idx] == '0') {
                s[idx] = '1';
                for (int j = idx+1; j < n; j++) s[j] = '0';
                cout << s << '\n';
            }
            idx--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s (n, '0');
    gen(n, s);
}
