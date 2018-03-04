#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int n, z[maxn];
string a, c, s;

void make_z (string a, int n, int f[]) {
    int l = 1, r = -1; f[0] = n;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = i; r = i-1;
            while (r < n-1 && a[r+1] == a[r-l+1]) r++;
            f[i] = r-l+1;
        } else {
            if (f[i-l] < r-i+1) f[i] = f[i-l];
            else {
                l = i;
                while (r < n-1 && a[r+1] == a[r-l+1]) r++;
                f[i] = r-l+1;
            }
        }
    }
}

void Z_function() {
    int l = 1, r = 1; z[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i-l+1]);
        while (i + z[i] <= n && s[i+z[i]] == s[z[i]+1]) ++z[i];
        if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
}

void z() {
    int l = 1, r = 1; z[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= r) z[i] = min(r-i+1, z[i-l+1]);
        while (i+z[i] <= n && s[i+z[i]] == s[z[i]+1]) z[i]++;
        if (i+z[i]-1 > r) r= i+z[i]-1, l = i;
    }
}

int main(){
  //  freopen ("z.inp", "r", stdin);
   // freopen ("z.out", "w", stdout);
    cin >> c >> s;
    int res = 0;
    a = c + "*" + s;
    n = a.size();
    make_z(a, n, z);
    for (int i = 0; i < n; i++)
        if (z[i] == c.size()) res++;
    cout << res;
    return 0;
}
