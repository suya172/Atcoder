#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    auto f = [&](ll n) -> double {
        return (double) a / sqrt(n + 1) + (double) b * n;
    };
    ll argmin = pow((double) a / (b * 2), 2. / 3.) - 1;
    ll l = max(argmin - 5, 0LL), r = min(argmin + 5, a / b);
    double ans = a;
    for (ll i = l; i <= r; i++) {
        ans = min(ans, f(i));
    }
    cout << fixed << setprecision(10) << ans << endl;
}
