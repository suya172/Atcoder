#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int main(){
    int N,K;
    cin>>N>>K;
    vector<int>A(N);
    rep(i,N) cin>>A[i];
    auto maxindex=*max_element(A.begin(),A.end());
    rep(i,K){
        int itr;
        cin>>itr;
        if(A[itr-1]==maxindex){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}