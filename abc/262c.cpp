#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int same = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= 1;
        if (a[i] == i) {
            same += 1;
        }
    }
    long long ans = (long long)same * (same - 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] > i and a[a[i]] == i) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
