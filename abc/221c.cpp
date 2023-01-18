#include<bits/stdc++.h>
using namespace std;

int main(void){
    string N;
    cin>>N;
    sort(N.begin(),N.end());
    int size=N.size();
    int ans=0;
    do{
        for(int i=1;i<size;++i){
            int a=0,b=0;
            for(int j=0;j<i;++j) a=a*10+N[j]-'0';
            for(int j=i;j<size;++j) b=b*10+N[j]-'0';
            ans=max(ans,a*b);
        }
    }while(next_permutation(N.begin(),N.end()));
    cout<<ans<<endl;
}