int lcs() {
    vector <int> a(n+1, 1e9);
    for (int i = 1; i <= n; i++)
        *lower_bound(a.begin(), a.end(), b[i]) = b[i];
    return lower_bound(a.begin(), a.end(), 1e9) - a.begin();
}
