#include<bits/stdc++.h>
using namespace  std;
using ll=long long;
int main(void){
    ll N,W;
    cin>>N>>W;
    vector<ll>cheese(N);
    for(int i=0;i<N;++i){
        ll a,b;
        cin>>a>>b;
        cheese[i]=a*10000+b;
    }
    sort(cheese.begin(),cheese.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<N;++i){
        ll A,B;
        A=cheese[i]/10000;
        B=cheese[i]%10000;
        if(W>B){
            ans+=A*B;
            W-=B;
        }else{
            ans+=A*W;
            break;
        }
    }
    cout<<ans<<endl;
}