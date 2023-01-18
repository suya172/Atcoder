#include<bits/stdc++.h>
using namespace std;
int main(void){
    int Q; cin>>Q;
    multiset<int> st;
    for(int i=0;i<Q;++i){
        int type; cin>>type;
        if(type==1){
            int x; cin>>x;
            st.insert(x);
        }
        if(type==2){
            int x,c; cin>>x>>c;
            while(c-- and st.find(x)!=st.end()){
                st.erase(st.find(x));
            }
        }
        if(type==3){
            cout<<*st.rbegin()-*st.begin()<<endl;
        }
    }
}