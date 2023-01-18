#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int main(){
    long long n,m;
    cin>>n>>m;
    vector<string>s(n);
    vector<string>t(m);
    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];
    long long temp=0;
    rep(i,m){
        while(s[temp]!=t[i]){
            cout<<"No"<<endl;
            temp++;
        }
        cout<<"Yes"<<endl;
        temp++;
    }
    return 0;
}