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
using vb = vector<bool>;
using vvb = vector<vb>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

#define pb push_back
#define mp make_pair
#define um unordered_map
#define siz size()
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
inline void dprint(const double& d,ll n = 10){cout << fixed << setprecision(n) << d << endl;}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

const ll MOD=1000000007;

int main(){
   vll prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
   vll dim(25);
   ll N; cin>>N;
   rep(i,25){
     ll x=prime[i];
     while(N/x>0){
        dim[i]+=N/x;
        x*=prime[i];
     }  
   }
   //4,4,2 24,2 14,4 74
   vll A={0,2,4,14,24,74};
   vll B(6);
   rep(i,25){
     ll x=dim[i];
     repd(j,6){
        if(x>=A[j]) B[j]++;
     }
   }
   rep(i,5){
    B[i]-=B[i+1];
   }
   //print(dim);
   //print(B);
   print(max((B[2]+B[3]+B[4]+B[5])*(B[2]+B[3]+B[4]+B[5]-1)*(B[2]+B[3]+B[4]+B[5]-2)/2,(ll)0)+max((B[2]+B[3]+B[4]+B[5])*(B[2]+B[3]+B[4]+B[5]-1)*B[1]/2,(ll)0)+max((B[4]+B[5])*(B[4]+B[5]-1),(ll)0)+max((B[4]+B[5])*(B[1]+B[2]+B[3]),(ll)0)+max((B[3]+B[4]+B[5])*(B[3]+B[4]+B[5]-1),(ll)0)+max((B[3]+B[4]+B[5])*(B[2]),(ll)0)+B[5]);
}