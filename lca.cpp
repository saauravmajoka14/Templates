#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define sz(x) (int)(x).size()

#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for(ll i=a; i<=b; i++)
#define REPr(i,a,b) for(ll i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
const int mod =1e9+7;
#define pct(x) __builtin_popcount(x)
#define clz(x) __builtin_clz(x)
#define pctl(x) __builtin_popcountll(x)
#define clzl(x) __builtin_clzll(x)
const ll inf= 1e17;
const ll ninf= -1e17;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {return (a + b) % m;}
ll mod_mul(ll a, ll b, ll m) { return (a * b) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

/*---------------------------------------------------------------------------------------------------------------------------*/
const int N=1e6+5;



vi G[N];
int P[N][20];
vi D(N);

void dfs(int s, int p, int d ){
    P[s][0]=p;
    D[s]=d;
    for(auto x: G[s]){
        if(x!=p){
            dfs(x,s,d+1);
        }
    }
}

int LCA(int a, int b){
    if(D[a]<D[b])swap(a,b);
    int k=D[a]-D[b];
    debug(k)
    REP(i,0,19){
        if(k & (1<<i)){
            a=P[a][i];
        }
    }
    if(a==b){
        return a;
    }
    REPr(i,19,0){
        if(P[a][i]!=P[b][i]){
            a=P[a][i];
            b=P[b][i];
        }
    }
    return P[a][0];
}









void solve(){

    int n,k; cin>>n>>k;
    REP(i,0,n){
        G[i].clear();
    }
    int x,y; cin>>x>>y;
    --x;--y;
    set<int>uni;
    REP(i,0,k-1){
        int a;
        cin>>a;
        a--;
        if(a == x || a==y)continue;
        uni.insert(a);
    }
    vi H;
    k=sz(uni);
    for(auto x: uni){
        H.pb(x);
    }
    debug(H)
    REP(i,1,n-1){
        int a,b; cin>>a>>b;
        G[--a].pb(--b);
        G[b].pb(a);
    }
    dfs(x,-1,0);

    REP(i,1,19){
        REP(j,0,n-1){
            if(j!=x)P[j][i]=P[P[j][i-1]][i-1];
            else P[j][i]=-1;
        }
    }

   
    

    



    
}
    

	


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
	#endif 
	#ifndef ONLINE_JUDGE
   	 freopen("Error.txt", "w", stderr);
	#endif
    fast;
    int t; cin>>t;
    while(t--)
    solve();

    
   


}
