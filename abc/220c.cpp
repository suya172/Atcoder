#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void){
    ll N,X;
    cin>>N;
    vector<ll>A(N);
    ll suma=0;
    for(int i=0;i<N;++i){
        cin>>A[i];
        suma+=A[i];
    }
    cin>>X;
    long long ans=0;
    ans+=(X/suma)*N;
    X%=suma;
    for(auto &i:A){
        ans++;
        X-=i;
        if(X<0) break;
    }
    cout<<ans<<endl;
}