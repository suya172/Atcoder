#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
// pair
using pii = pair<int, int>;
// vector
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using vpii = vector<pii>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define itn int

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {{double x; cin >> x; return x;}}
inline string in_str() {string x; cin >> x; return x;}
inline int ctoi(char c) {return c - '0';}
// vector_finder: (arg)elementを vectorの先頭から(arg)search_lengthまで先頭から検索し、boolを返す
// (arg)search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
      res=res*x%mod;
    }
    return res;
}
int main(void){
    int H1,W1,H2,W2; cin>>H1>>W1;
    vvi A(H1,vi(W1));
    rep(i,H1){
        rep(j,W1) cin>>A[i][j];
    }
    cin>>H2>>W2;
    vvi B(H2,vi(W2));
    rep(i,H2){
        rep(j,W2) cin>>B[i][j];
    }
    bool ok=false;
    int a=H1-H2,b=W1-W2;
    vi hvec(H1,0),wvec(W1,0);
    rep(i,a) hvec[hvec.size()-i-1]=1;
    rep(i,b) wvec[wvec.size()-i-1]=1;
    do{
        do{
            // for(const auto& i:hvec) cerr<<i<<" ";
            // cerr<<"\n";
            // for(const auto& i:wvec) cerr<<i<<" ";
            // cerr<<"\n";

            int tmp1=0;
            int tmp2=0;

            bool ok2=true;
            rep(i,H2){
                while(hvec[tmp1]==1) tmp1++;
                rep(j,W2){
                    while(wvec[tmp2]==1) tmp2++;

                    // cerr<<"("<<tmp1<<","<<tmp2<<")"<<"\n";

                    if(A[tmp1][tmp2]!=B[i][j]) ok2=false;
                    tmp2++;
                }
                tmp1++;
                tmp2=0;
            }
            if(ok2) ok=true;
        }while(next_permutation(wvec.begin(),wvec.end()));
    }while(next_permutation(hvec.begin(),hvec.end()));
    YesNo(ok);
}