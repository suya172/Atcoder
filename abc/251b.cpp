#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)
using ll=long long;
int main(void){
    ll n,w;
    cin>>n>>w;
    vector<ll>a(n);
    rep(i,n) cin>>a[i];
    vector<int>judge(w+1);
    rep(i,n){
        ll sum=a[i];
        if(sum<=w) judge[sum]=1;
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
        ll sum=a[i]+a[j];
        if(sum<=w) judge[sum]=1;
        }
    }
    rep(i,n){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
            ll sum=a[i]+a[j]+a[k];
            if(sum<=w) judge[sum]=1;
            }
        }
    }
    int ans=0;
    rep(i,w+1) ans+=judge[i];
    cout<<ans<<endl;
}