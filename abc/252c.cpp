#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int main(void){
    int N;
    cin>>N;
    vector<string>S(N);
    rep(i,N) cin>>S[i];
    int ans=100000;
    rep(i,10){
        string num=to_string(i);
        vector<int>t(0);
        rep(j,N){
            int tt=S[j].find(num);
            int kaburikazu=0;
            for(auto &i : t){
                if(i%10==tt){
                    kaburikazu++;
                }
            }
            t.push_back(tt+10*kaburikazu);
        }
        int maxt=*max_element(t.begin(),t.end());
        if(maxt<ans) ans=maxt;
    }
    cout<<ans<<endl;
}