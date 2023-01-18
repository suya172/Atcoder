#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int main(void){
    int N,K;
    cin>>N>>K;
    vector<int>score(N);
    rep(i,N){
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        score[i]=p1+p2+p3;
    }
    vector<int>great=score;
    sort(great.begin(),great.end());
    rep(i,N){
        auto itr=upper_bound(great.begin(),great.end(),score[i]+300);
        int num=itr-great.begin();
        if(N-num+1<=K) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}