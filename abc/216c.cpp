#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    string ans;
    while(N>0){
        if(N%2==0){
            N/=2;
            ans.push_back('B');
        }else{
            N--;
            ans.push_back('A');
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}