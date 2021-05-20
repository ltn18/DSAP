// author: Lam Nguyen
// travelling salesman - NP problem

/**
 *  @idea:
 *  Traveling all nodes, visiting each once, except
 *  the first node can be visited twice
 *  Backtrack x[i] takes all possibilities that x[i-1] can go to
 *  and that possibility has not been visited
 *  t[i] is the total cost of travelling from x[0] to x[i]
 *  Goal: find the route that has lowest cost
 *
 *  @input:
 *  4 6
    0 1 3
    0 2 2
    0 3 1
    1 2 1
    1 3 2
    2 3 4
    @output:
    Min Cost: 6
    0->2->1->3->0
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int oo = 1e9;

int c[MAXN][MAXN]; // cost array
int x[MAXN], best[MAXN]; // x: try possibilities; best: best config
int t[MAXN]; // t[i] = price to go from x[0] -> x[i];
bool avail[MAXN];
int minCost;

void enter(int m, int n) {
    int start, end, cost;

    // set cost array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) c[i][j] = 0;
            else c[i][j] = oo;
        }
    }

    // update cost array
    for (int i = 0; i < n; i++) {
        cin >> start >> end >> cost;
        c[start][end] = cost;
        c[end][start] = cost;
    }
}

void init(int m) {
    // all nodes available
    for (int i = 0; i < m; i++) avail[i] = true;
    x[0] = 0; // start at 0
    t[0] = 0; // total cost = 0 at 0
    avail[0] = false;
    minCost = oo;
}

void copy(int m) {
    for (int i = 0; i < m; i++) {
        best[i] = x[i];
    }
}

void attempt(int m, int i) {
    for (int j = 1; j < m; j++) {
        if (avail[j]) {
            x[i] = j;
            t[i] = t[i-1] + c[x[i-1]][j];
            if (t[i] < minCost) {
                if (i < m-1) {
                    avail[j] = false;
                    attempt(m, i+1);
                    avail[j] = true;
                }
                else {
                    if (t[m-1] + c[x[m-1]][0] < minCost) {
                        copy(m); // copy x to best to update best
                        minCost = t[m-1] + c[x[m-1]][0];
                    }
                }
            }
        }
    }
}

void printCostArray(int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << endl;
        }
    }
}

void printBest(int m) {
    cout << "Min Cost: " << minCost << '\n';
    for (int i = 0; i < m; i++) {
        cout << best[i] << "->";
    }
    cout << best[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); // fast io
//    freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
    int m, n; // m: number of nodes
    cin >> m >> n;
    enter(m, n);
    init(m);
    attempt(m, 1);
    printBest(m);
}

