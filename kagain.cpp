#include <iostream>

using namespace std;

int main(){
    freopen ("in.inp", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        int l[maxn], r[maxn];
        int res = 0, L, R;
        stack <int> st;
        st.push(0);

        for (int i = 1; i <= n; i++) {
            while (st.size() > 0 && a[st.top()] >= a[i]) {
                r[st.top()] = i-1;
                st.pop();
            }
            l[i] = st.top()+1;
            st.push(i);
        }
        while (st.size() > 0) q[q.top()] = n, q.pop();

    }
    return 0;
}
