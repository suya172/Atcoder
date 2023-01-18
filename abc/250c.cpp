#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,q;
    cin>>n>>q;
    vector<int>ns(n);
    vector<int>qs(q);
    for(int i=1;i<=n;i++) ns[i-1]=i;
    for(int i=0;i<q;i++){
        int b; 
        cin>>b;
        qs[i]=b-1;
    }
    for(int i=0;i<q;i++){
        int a;
        int num=find(ns.begin(),ns.end(),qs[i]);
        if(num==n-1){
            a=ns[n-1];
            ns[n-1]=ns[0];
            ns[0]=a;
        } else{
            a=ns[num+1];
            ns[num+1]=ns[num];
            ns[num]=a;
        }
    }
    for(int i=0;i<n;++i){
        if(i==n-1) cout<<ns[i]<<endl;
        else cout<<ns[i]<<" ";
    }
}