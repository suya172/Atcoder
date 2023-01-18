#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int main(void){
    int H,W,N; cin>>H>>W>>N;
    vector<int>A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector<int>xs;
    rep(i,N) xs.push_back(A[i]);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    rep(i,N) A[i]=lower_bound(xs.begin(),xs.end(),A[i])-xs.begin();

    vector<int>ys;
    rep(i,N) ys.push_back(B[i]);
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    rep(i,N) B[i]=lower_bound(ys.begin(),ys.end(),B[i])-ys.begin();
    rep(i,N){
        cout<<A[i]+1<<" "<<B[i]+1<<endl;
    }
}