#include <bits/stdc++.h>
using namespace std;
#define rep(i, x) for(int i = 0; i < (x); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<long long>> cum(k, vector<long long>(n + 1));
    rep(j, k) {
        rep(i, n) {
            cum[j][i + 1] = cum[j][i] + (i % k == j ? a[i] : 0);
        }
    }
    auto get = [&](int j, int l, int r) {
        return cum[j][r] - cum[j][l];
    };
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r, --l;
        bool same = 1;
        long long val = get(0, l, r);
        for(int j = 1; j < k; j++) {
            same &= val == get(j, l, r);
        }
        cout << (same ? "Yes" : "No") << endl;
    }
}
