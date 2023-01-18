#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    ll ans=1;
    vector<string>ss;
    ll tt=0;
    for(int i=1;i<=n;++i){
        string s;
        ll t;
        cin>>s>>t;
        bool aru=false;
        for(int j=0;j<ss.size();++j){
            if(s==ss[j]){
                aru=true;
                break;
            }
        }
        if(aru){
            continue;
        }else{
            ss.push_back(s);
            if(t>tt){
                tt=t;
                ans=i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}