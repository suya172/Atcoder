#include<bits/stdc++.h>
using namespace std;
int main(void){
    int N,K; cin>>N>>K;
    vector<int>a(N);
    vector<vector<int>>as(K,vector<int>(0));
    for(int i=0;i<N;++i){
        int j; cin>>j;
        a[i]=j;
        as[i%K].push_back(j);
    }
    for(int i=0;i<K;++i) sort(as[i].begin(),as[i].end());
    sort(a.begin(),a.end());
    for(int i=0;i<N;++i){
        if(a[i]!=as[i%K][i/K]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}