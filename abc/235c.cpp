#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using ll=long long;

int main(){
    ll n,q;
    cin>>n>>q;
    ll max=pow(10,9);
    vector<vector<ll>>pos(max,vector<ll>(0));
    rep(i,n){
        ll a;
        cin>>a;
        pos[a].push_back(i);
    }
    rep(i,q){
        ll x,k;
        cin>>x>>k;
        if(pos[x].size()<k) cout<<-1<<endl;
        else cout<<pos[x][k]+1<<endl;
    }
    return 0;
}