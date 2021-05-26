// author: Lam Nguyen
// generating abc string that satisfies:
//      * length n
//      * 2 consecutive substring is different
//      * has least 'c' character

/**
 * @idea:
 *   in 4 consecutive characters there must be 1 'c'
 *   minC >= t[i] + (n-i) % 4
 *
 * @note: mod = %, div = / (this is where the bug comes from)
 *
 * @input: 10
 * @output:
 *  abacabcbab
    'c' letter count: 2
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
char x[MAXN], best[MAXN]; // array of characters
int t[MAXN]; // t[i] = number of 'c' from x[0] to x[i]
int minC = 1e6;

// same(i, L) check if a substring of L characters end at x[i] == a substring comes before that
bool same(int i, int L) {
    int j = i-L; // last position coming before that substring
    for (int k = 0; k < L; k++) {
        if (x[i-k] != x[j-k]) return false;
    }
    return true;
}

// check if x[i] violates non-repetitiveness of the substring
bool check(int i) {
    // try all lengths
    for (int l = 1; l <= i / 2; l++) {
        if (same(i, l)) return false;
    }
    return true;
}

void keepResult(int n) {
    minC = t[n];
    for (int i = 1; i <= n; i++) best[i] = x[i];
}

void printResult(int n) {
    for (int i = 1; i <= n; i++) cout << best[i];
    cout << '\n';
    cout << "'c' letter count: " << minC << '\n';
}

void init(int n) {
    for (int i = 1; i <= n; i++) x[i] = '-';
    t[0] = 0; // i wonder why this works?
    minC = n;
}

void attempt(int n, int i) {
    for (char j = 'a'; j <= 'c'; j++) {
        x[i] = j;
        if (check(i)) {
            if (j == 'c') t[i] = t[i-1] + 1;
            else t[i] = t[i-1];

            if (t[i] + (n-i)/4 < minC) {
                if (i == n) keepResult(n);
                else attempt(n, i+1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    attempt(n, 1);
    printResult(n);
}
