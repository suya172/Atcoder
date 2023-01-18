#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using ll=long long;

int main(){
    ll N,Q;
    cin>>N>>Q;
    vector<ll>A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    rep(i,Q){
        ll x;
        cin>>x;
        auto pos=lower_bound(A.begin(),A.end(),x);
        int index=pos-A.begin();
        cout<<N-index<<endl;
    }
    return 0;
}