#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,ans=0; cin>>N;
    for(int i=1;i<N;++i){
        ans+=floor((N-1)/i);
    }
    cout<<ans<<endl;
}