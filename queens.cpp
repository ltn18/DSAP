// author: Lam Nguyen
// place n queens in nxn chessboard so that no 2 queens are threatening each other

/**
    @idea:
    - consider the table north east - south west:
        * we have constant C = row + col
        * 2 <= C <= 2*n
    - consider the table south east - north west:
        * we have constant C = row - col
        * 1-n <= C <= n-1
    - the reason why we need those 2 cases above is that
      we need to control the diagonals threatened by a queen
    - suppose queen i is in row ith:
        -> choose col j so that
            diag(i+j),  is free
            diag(i-j)   is free
            j           is free
    - if i = n -> we have 1 solution

    @input: 5
    @output:
    (1, 1); (2, 3); (3, 5); (4, 2); (5, 4);
    (1, 1); (2, 4); (3, 2); (4, 5); (5, 3);
    (1, 2); (2, 4); (3, 1); (4, 3); (5, 5);
    (1, 2); (2, 5); (3, 3); (4, 1); (5, 4);
    (1, 3); (2, 1); (3, 4); (4, 2); (5, 5);
    (1, 3); (2, 5); (3, 2); (4, 4); (5, 1);
    (1, 4); (2, 1); (3, 3); (4, 5); (5, 2);
    (1, 4); (2, 2); (3, 5); (4, 3); (5, 1);
    (1, 5); (2, 2); (3, 4); (4, 1); (5, 3);
    (1, 5); (2, 3); (3, 1); (4, 4); (5, 2);
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int x[MAXN]; // storing index of columns
bool a[2*MAXN]; // Columns free check
bool b[2*MAXN];// East North - West South
bool c[2*MAXN]; // East South - West North -> need to convert 1-n ... n-1 to 0 ... 2n-2

void init(int n) {
    for (int i = 0; i < 2*n; i++) {
        a[i] = true;
        b[i] = true;
        c[i] = true;
    }
}

void print(int s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << i+1 << ", " << s[i] << "); ";
    }
    cout << '\n';
}

void setFalse(int i, int j, int n) {
    a[j] = false;
    b[i+j] = false;
    c[i-j+n-1] = false;
}

void setTrue(int i, int j, int n) {
    a[j] = true;
    b[i+j] = true;
    c[i-j+n-1] = true;
}

void attempt(int n, int i) {
    if (i == n) {
        print(x, n);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (a[j] && b[i+j] && c[i-j+n-1]) {
            x[i] = j+1;
            setFalse(i, j, n);
            attempt(n, i+1);
            setTrue(i, j, n);
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    attempt(n, 0);
}

