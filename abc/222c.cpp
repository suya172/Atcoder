#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<n;++i)
int judge(char player1,char player2){
    if(player1==player2) return 0;

    if(player1=='G'&&player2=='C') return 1; 
    if(player1=='C'&&player2=='P') return 1; 
    if(player1=='P'&&player2=='G') return 1;

    return 2; 
}

int main(void){
    vector<int>point(101,0);
    int N,M;
    cin>>N>>M;
    vector<int>number(N*2);
    rep(i,N*2) number[i]=i;
    vector<string>A(N*2);
    rep(i,N*2) cin>>A[i];
    rep(i,M){
        rep(j,N){
            int p1=number[j*2],p2=number[j*2+1];
            int result=judge(A[p1][i],A[p2][i]);
            if(result==1) point[p1]++;
            if(result==2) point[p2]++;
        }
        sort(number.begin(),number.end(),[&](int a,int b){
            if(point[a]!=point[b]) return point[a]>point[b];
                else return a<b;
        });
    }
    for(auto &i:number) cout<<i+1<<endl;
}