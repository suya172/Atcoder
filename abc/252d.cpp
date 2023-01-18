#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void){
    ll N;
    cin>>N;
    vector<ll>A(N);
    for(int i=0;i<N;++i) cin>>A[i];
    ll ans;
    ans=(N*(N-1)*(N-2))/6;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            for(int k=j+1;k<N;++k){
                if((A[i]==A[j])||(A[j]==A[k])||(A[k]==A[i]))  ans--;
            }
        }
    }
    cout<<ans<<endl;
}