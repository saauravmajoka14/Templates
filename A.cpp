
const int N=1e5+100;
#define int ll

int par[N];
int sz[N];

int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}

void unite(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;

}

void solve(){
    int n; cin>>n;
    REP(i,0,n-1){
        par[i]=i;
        sz[i]=1;
    }
    int m; cin>>m;
    REP(i,0,m-1){
        int q;cin>>q;
        if(q==1){
            int a,b; cin>>a>>b;
            unite(a,b);
        }else{
            int a; cin>>a;
            cout<<find(a)<<endl;
        }
    }

}

