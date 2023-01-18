#include<bits/stdc++.h>
using namespace std;
int main(void){
    int N; cin>>N;
    vector<vector<int>>A(30,vector<int>(30,1));
    for(int i=2;i<N;++i){
        for(int j=1;j<i;++j){
            A[i][j]=A[i-1][j-1]+A[i-1][j];
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<i+1;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}