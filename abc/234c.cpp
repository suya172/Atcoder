#include<bits/stdc++.h>
using namespace std;

int main(void){
    long long k;
    cin>>k;
    bitset<60>s(k);
    int itr=60;
    while(true){
        itr--;
        if(s.test(itr)) break;
    }
    while(itr>=0){
        if(s.test(itr)) cout<<'2';
        else cout<<'0';
        itr--;
    }
    cout<<endl;
    return 0;
}