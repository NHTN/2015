#include <bits/stdc++.h>
#define maxn 105
#define pb push_back

using namespace std;

int a[maxn][maxn];
int n,m;

void euler() {
    stack <int> s;
    s.push(1);
    while (s.size()) {
        int u = s.top();
        bool kt = true;
        for (int v = 1; v <= n; v++)
        if (a[u][v] > 0) {
            a[u][v]--;
            a[v][u]--;
            kt = false;
            s.push(v);
            break;
        }
        if (kt) {
            cout << u << " ";
            s.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("IN.INP", "r", stdin);
    freopen ("IN.OUT", "w", stdout);
    cin >> n;
    while (n--) {
        int u, v, k;
        cin >> u >> v >> k;
        a[u][v] = k;
        a[v][u] = k;
    }
    euler();
    return 0;
}
