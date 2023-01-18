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
    ll n,k;  cin>>n>>k;
    vvll c(n,vll(n));

    //調整必須
    ll check_depth=1;

    vll max_lines(k+1);
    vll max_nums(k+1);
    vector<vector<vector<ll>>> num_per_line(k+1,vvll(n));
    rep(i,n){
        rep(j,n){
            char a; cin>>a;
            int ai=a-'0';
            c[i][j]=ai;
            num_per_line[ai][i].push_back(j);
        }
    }
    vvll num_juni(k+1);
    vll iton;
    rep(i,n) iton.push_back(i);
    rrep(i,k){
        num_juni[i]=iton;
        sort(num_juni[i].begin(),num_juni[i].end(),[&](int const& p,int const& q){
            return num_per_line[i][p].size()>num_per_line[i][q].size();
        });
    } 
    rrep(i,k){
        ll max_num=0,line;
        reps(j,check_depth,n-check_depth){
            ll num=0;
            rep(h,check_depth*2+1){
                num+=num_per_line[i][j-check_depth+h].size();
            }
            if(num>max_num){ 
                max_num=num;
                line=j;
            }
        }
        max_lines[i]=line;
        max_nums[i]=max_num;
    }
    reps(i,1,k+1) cerr<<max_lines[i]<<" ";
    cerr<<"\n";
    cerr<<"_____________________"<<"\n";
    reps(i,1,k+1) cerr<<max_nums[i]<<" ";
    cerr<<"\n";
    cerr<<"_____________________"<<"\n";
    rrep(i,k){
        rep(h,n) cerr<<num_juni[i][h]<<" ";
        cerr<<"\n";
    }

    //ブロックを中央に寄せる動き（書きかけ）
    // vl main_direction(k+1);
    // rrep(i,k){
    //     double a=double(n)/2-max_lines[i];
    //     if(a>=0) main_direction[i]=1;
    //     else main_direction[i]=-1;
    // }
    // rrep(i,k){
    //     rrep(h,k){
    //         if(i==h) continue;
            
    //     }
    // }

    //とりあえず点数さえ取れればいい動き

    ll count=0;
    vvll move(0,vll(4)),connect(0,vll(4));
    vector<vector<bool>> already_connect(n,vector<bool>(n));
    auto MOVE=[&move,&count,&c](ll a1,ll a2,ll b1,ll b2){
    vll a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(b1);
    a.push_back(b2);
    move.push_back(a);
    count++;
    swap(c[a1][a2],c[b1][b2]);
    };
    auto CONNECT=[&connect,&count,&already_connect](ll a1,ll a2,ll b1,ll b2){
    vll a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(b1);
    a.push_back(b2);
    connect.push_back(a);
    count++;
    if(a1==b1){
        ll s=min(a2,b2);
        rep(i,abs(a2-b2)+1) already_connect[a1][s+i]=true;
    }else{
        ll s=min(a1,b1);
        rep(i,abs(a1-b1)+1) already_connect[s+i][a2]=true;
    }
    };
    rrep(i,k){
        ll hidarihashi=-1;
        rep(t,n){
            if(count>=k*100-3) break;
            if(c[max_lines[i]][t]==i){
                if(hidarihashi==-1) hidarihashi=t;
                else{
                    CONNECT(max_lines[i],t,max_lines[i],hidarihashi);
                }
                if(c[max_lines[i]-1][t]==i){
                    CONNECT(max_lines[i]-1,t,max_lines[i],t);
                }
                if(c[max_lines[i]+1][t]==i){
                    CONNECT(max_lines[i]+1,t,max_lines[i],t);
                }
                hidarihashi=t;
            }
            if(c[max_lines[i]][t]==0){
                if(c[max_lines[i]-1][t]==i&&!already_connect[max_lines[i]-1][t]){
                    MOVE(max_lines[i]-1,t,max_lines[i],t);
                if(hidarihashi==-1) hidarihashi=t;
                else{
                    CONNECT(max_lines[i],t,max_lines[i],hidarihashi);
                }
                if(c[max_lines[i]+1][t]==i&&!already_connect[max_lines[i]+1][t]){
                    CONNECT(max_lines[i]+1,t,max_lines[i],t);
                }
                hidarihashi=t;
                }else if(c[max_lines[i]+1][t]==i&&!already_connect[max_lines[i]+1][t]){
                    MOVE(max_lines[i]+1,t,max_lines[i],t);
                    if(hidarihashi==-1) hidarihashi=t;
                    else{
                    CONNECT(max_lines[i],t,max_lines[i],hidarihashi);
                    hidarihashi=t;
                }
                }
            }
            if(c[max_lines[i]][t]!=i&&c[max_lines[i]][t]!=0&&!already_connect[max_lines[i]][t]){
                if(hidarihashi!=-1){
                    if(c[max_lines[i]+1][t]==0){
                        MOVE(max_lines[i],t,max_lines[i]+1,t);
                    }else if(c[max_lines[i]-1][t]==0){
                        MOVE(max_lines[i],t,max_lines[i]-1,t);
                    }else hidarihashi=-1;
                }
            }
        }
    }

    //要調整
    ll REPEAT=0;

    vll line_tmps(k+1,0);
    rep(h,REPEAT){
        rrep(i,k){
            while(num_juni[i][line_tmps[i]]==max_lines[i]) line_tmps[i]++;
            ll hidarihashi=-1;
            bool connected=false;
            rep(t,n){
                if(count>=k*100-n+1) break;
                if(c[num_juni[i][line_tmps[i]]][t]==i){
                    if(already_connect[num_juni[i][line_tmps[i]]][t]){
                        hidarihashi=-1;
                        connected=false;
                        continue;
                    }
                    if(hidarihashi==-1) hidarihashi=t;
                    else{
                        CONNECT(num_juni[i][line_tmps[i]],hidarihashi,num_juni[i][line_tmps[i]],t);
                        connected=true;
                        hidarihashi=t;
                    }
                    if(c[num_juni[i][line_tmps[i]]-1][t]==i){
                        CONNECT(num_juni[i][line_tmps[i]]-1,t,num_juni[i][line_tmps[i]],t);
                    }
                    if(c[num_juni[i][line_tmps[i]]+1][t]==i){
                        CONNECT(num_juni[i][line_tmps[i]]+1,t,max_lines[i],t);
                    }
                }
                if(c[num_juni[i][line_tmps[i]]][t]==0){
                    if(c[num_juni[i][line_tmps[i]]-1][t]==i&&!already_connect[num_juni[i][line_tmps[i]]-1][t]){
                        MOVE(num_juni[i][line_tmps[i]]-1,t,c[num_juni[i][line_tmps[i]]][t],t);
                        if(hidarihashi!=-1){
                            CONNECT(num_juni[i][line_tmps[i]],hidarihashi,num_juni[i][line_tmps[i]],t);
                            connected=true;
                        }
                        hidarihashi=t;
                        if(c[num_juni[i][line_tmps[i]]+1][t]==i&&!already_connect[num_juni[i][line_tmps[i]]+1][t]){
                            CONNECT(num_juni[i][line_tmps[i]],t,num_juni[i][line_tmps[i]]+1,t);
                        }
                    }else if(c[num_juni[i][line_tmps[i]]+1][t]==i&&!already_connect[num_juni[i][line_tmps[i]]+1][t]){
                                MOVE(num_juni[i][line_tmps[i]]+1,t,c[num_juni[i][line_tmps[i]]][t],t);
                                if(hidarihashi!=-1){
                                CONNECT(num_juni[i][line_tmps[i]],hidarihashi,num_juni[i][line_tmps[i]],t);
                                connected=true;
                                }
                                hidarihashi=t;
                            }
                }
                if(c[num_juni[i][line_tmps[i]]][t]!=0&&c[num_juni[i][line_tmps[i]]][t]!=i){
                    if(already_connect[num_juni[i][line_tmps[i]]][t]){
                        hidarihashi=-1;
                        connected=false;
                        continue;
                    }
                    if(c[num_juni[i][line_tmps[i]+1]][t]=0) MOVE(num_juni[i][line_tmps[i]],t,num_juni[i][line_tmps[i]+1],t);
                    else if(c[num_juni[i][line_tmps[i]-1]][t]=0) MOVE(num_juni[i][line_tmps[i]],t,num_juni[i][line_tmps[i]-1],t);
                    else{
                        hidarihashi=-1;
                        connected=false;
                    }
                }
            }
        }
    }

    //出力
    cout<<move.size()<<"\n";
    rep(i,move.size()){
        for(const auto& h:move[i]) cout<<h<<" ";
        cout<<"\n";
    }
    cout<<connect.size()<<"\n";
    rep(i,connect.size()){
        for(const auto& h:connect[i]) cout<<h<<" ";
        cout<<"\n";
    }
}