#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)
int main(){
    long long N; cin>>N;
    vector<long long> S(N),T(N);
    rep(i,N) cin>>S[i];
    rep(i,N) cin>>T[i];
    vector<long long>ans=T;
    rep(i,N*2) ans[(i+1)%N]=min(ans[(i+1)%N],ans[i%N]+S[i%N]);
    for(int i:ans) cout<<i<<endl;
}