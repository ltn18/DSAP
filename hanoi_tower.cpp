// author: Lam Nguyen
// Hanoi Tower problem
#include <bits/stdc++.h>
using namespace std;

void move(int n, int x, int y) {
    if (n == 1) cout << "Move 1 disk from " << x << " to " << y << '\n';
    else {
        // assume x,y,z = {1,2,3} -> z = 6-x-y
        int z = 6-x-y;
        move(n-1, x, z); // move n-1 disks from x to z
        move(1, x, y); // move biggest disk from x to y
        move(n-1, z, y); // move n-1 disks from z to y
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); // fast io
    int n; cin >> n;
    move(n, 1, 2);
}
