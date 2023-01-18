#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    pair<ll,ll>a,b;
    cin>>a.first>>a.second>>b.first>>b.second;
    vector<int>e={1,1-1,-1,2,2,-2,-2};
    vector<int>q={2,-2,2,-2,1,-1,1,-1};
    for(int i=0;i<8;++i){
        for (int k=0;k<8;++k)
        {
            if(a.first==b.first+e[i]+e[k]&&a.second==b.second+q[i]+q[k]){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}