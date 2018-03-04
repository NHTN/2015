#include <bits/stdc++.h>
#define maxn 105
using namespace std;

bool a[maxn][maxn], Free[maxn];
int x[maxn];
int n, m;

void print () {
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << x[1] << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++)
        if (Free[j] && a[x[i-1]][j]) {
            x[i] = j;
            if (i < n) {
                Free[j] = false;
                Try (i+1);
                Free[j] = true;
            } else
        if (a[j][x[1]]) print();
        }
}

void solve() {
    memset (Free, true, sizeof(Free));
    Free[1] = false;
    x[1] = 1;
    Try(2);
}

int main()
{
   /* ios::sync_with_stdio(0);
    cin.tie(0);*/
    freopen ("HAMILTON.INP", "r", stdin);
    freopen ("HAMILTON.OUT", "w", stdout);
    cin >> n >> m;
    for (int i =1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        cout << u << " " << v << endl;
        a[u][v] = true;
        a[v][u] = true;
    }
    solve();
    return 0;
}
