#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<double> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    double t = 0, ans = 0;
    for(int i = 0; i < n; i++) t += a[i] / b[i];
    t /= 2;
    for(int i = 0; i < n; i++){
        ans += min(a[i], t * b[i]);
        t -= min(a[i] / b[i], t);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}
