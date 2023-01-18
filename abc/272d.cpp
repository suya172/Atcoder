#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define rep3(i,m,n) for(ll i = m; i<(ll)(n); i++)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main() {
    ll n,m;
    cin >> n >> m;
    
    set<P> v;
    rep(i,n)rep(j,n){
        if(i*i+j*j == m)v.insert(P(i,j));
    }
    for(P p: v){
        v.insert(P(p.first, -p.second));
        v.insert(P(-p.first, p.second));
        v.insert(P(-p.first, -p.second));
    }
    
    vector<vector<ll>> ans(n,vector<ll>(n,-1));
    ans[0][0] = 0;
    queue<P> q;
    q.push(P(0,0));
    while(!q.empty()){
        P xy = q.front();
        q.pop();
        ll x = xy.first;
        ll y = xy.second;
        for(P p: v){
            ll nx = x + p.first, ny = y + p.second;
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(ans[nx][ny]!=-1)continue;
                ans[nx][ny] = ans[x][y] + 1;
                q.push(P(nx, ny));
            }
        }
    }
    
    rep(i,n){
        rep(j,n)cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
