#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    ll N; cin>>N;
    vector<ll> s;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            s.push_back(i);
            if(i*i!=N) s.push_back(N/i);
        }
    }
    sort(s.begin(),s.end());
    for(const auto& i:s) cout<<i<<"\n";
}