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

#define pb push_back
#define mp make_pair
#define um unordered_map
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
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

const ll MOD=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
      res=res*x%MOD;
    }
    return res;
}
ll f(pair<int,int>p1,pair<int,int>p2,pair<int,int>p3){
    return (p2.first - p1.first)*(p3.second - p1.second)-(p2.second - p1.second)*(p3.first - p1.first);
}
//二点間を結ぶ線分が交わるかどうか
bool iscross(pair<int,int>p1,pair<int,int>p2,pair<int,int>p3,pair<int,int>p4){
  ll t1,t2,t3,t4;
  t1 = f(p1, p2, p3);
  t2 = f(p1, p2, p4);
  t3 = f(p3, p4, p1);
  t4 = f(p3, p4, p2);
  return t1*t2 < 0.0 && t3*t4 < 0.0;
}

ll nCk(int n, int k) {
    ll x = 1; // n!の初期値
    ll y = 1; // (n-k)!の初期値
    ll z = 1; // k!の初期値

    // 演算ごとにMODをとる
    rep(i, n) x = (x * (n - i)) % MOD; // n!を計算
    rep(i, n - k) y = (y * (n - k - i)) % MOD; // (n-k)!を計算
    rep(i, k) z = (z * (k - i)) % MOD; // k!を計算

    // 先に分母をMODの世界で計算してあげる
    ll yz = (y * z) % MOD;

    // 定義通りに計算
    return (x / (yz)) % MOD;
}

int main(){
   vector<pair<int,int>> vec;
   vector<string> board(9);
   int ans=0;
   rep(i,9)rep(j,9){
    char c; cin>>c;
    board[i].push_back(c);
    if(c=='#') vec.push_back(make_pair(j,i));
   }
   int size=vec.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int h=j+1;h<size;h++){
                for(int k=h+1;k<size;k++){
                    if(vec[j].first-vec[i].first==vec[h].second-vec[])
                }
            }
        }
    }
    print(ans);
}