#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string black,white;
    rep(i,b) black.push_back('#');
    rep(i,b) white.push_back('.');
    bool w_b1=true;
    bool w_b2=true;
    rep(i,n){
        w_b1=w_b2;
        string ans;
        rep(k,n){
            if(w_b1) ans+=white;
            else ans+=black;
            w_b1=!w_b1;
        }
        rep(k,a) cout<<ans<<endl;
        w_b2=!w_b2;
    }
}