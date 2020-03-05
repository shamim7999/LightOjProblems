#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld e, ld b){ return log(e)/log(b); }

vector < pair<int, pair<int,int> > > graph;
vector < pair<int,int> > g[mx];
map < pair<int,int>, int > mp;
int parent[mx];
int n,danger=-1,danger2=INT_MAX;
int par[mx][24],level[mx], dis[mx][24], dis2[mx][24];

void clr()
{
    for(int i=0; i<=n; i++) g[i].clear(), level[i]=-1;
    mp.clear(), graph.clear();
    danger=-1,danger2=INT_MAX;
}

void dfs(int node, int baba)
{
    par[node][0]=baba, level[node] = 1+level[baba];
    for(auto it : g[node]) if(it.fr!=baba) dis[it.fr][0] = it.se, dis2[it.fr][0] = it.se, dfs(it.fr,node);
}

void lca(int u, int v)
{
     if(level[u]<level[v]) swap(u,v);

    int diff = level[u]-level[v];

    while(diff>0){
        int cc = LOG(diff,2);
        danger = max(danger, dis[u][cc]);
        danger2 = min(danger2, dis2[u][cc]);
        u = par[u][cc];
        diff -= (1<<cc);
    }
    while(u!=v){
        int cc = LOG(level[u],2);
        if(cc>0 && par[u][cc] == par[v][cc]) cc=0;
        danger = max({danger, dis[u][cc], dis[v][cc]});
        danger2 = min({danger2, dis2[u][cc], dis[v][cc]});
        u = par[u][cc], v = par[v][cc];
    }
    //return danger;
}

int Findparent(int x)
{
    return (x==parent[x])?x:(parent[x]=Findparent(parent[x]));
}

void Union(int x,int y)
{
    parent[Findparent(x)]=parent[Findparent(y)];
}

void kruskal()
{
    //cout<<0;
    sort(graph.begin(),graph.end());
    for(int i=0;i<graph.size();i++)
    {
      int u=graph[i].second.first;
      int v=graph[i].second.second;
      int w=graph[i].first;

      if(Findparent(u)!=Findparent(v)){
        g[u].pb({v,w});
        g[v].pb({u,w});
        mp[{u,v}]=w, mp[{v,u}]=w;
        Union(u,v);
      }
    }
}

void ini()
{
    for(int i=1; i<=n; i++) parent[i]=i;
}

void solve(int tc)
{
    clr();
    scanf("%d", &n);
    for(int i=0,n1,n2,w; i<n-1; i++) scanf("%d %d %d", &n1, &n2, &w), graph.pb({w,{n1,n2}});
    ini();
    kruskal();
    memo(par,-1);
    memo(dis,0);
    memo(dis2,0);
    dfs(1,0);
    for(int j=1; j<=22; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1]!=-1){
                par[i][j] = par[par[i][j-1]][j-1],dis[i][j]=max(dis[i][j-1],dis[par[i][j-1]][j-1]);
                dis2[i][j]=min(dis2[i][j-1],dis2[par[i][j-1]][j-1]);
            }
            else par[i][j]=-1;
        }
    }
    int q;
    scanf("%d", &q);
    printf("Case %d:\n", tc);
    while(q--){
        int a,b;
        scanf("%d %d", &a, &b);
        lca(a,b);
        printf("%d %d\n", danger2, danger);
        danger = -1, danger2 = INT_MAX;
    }

}

int main()
{
    //freopen("text.txt", "r", stdin);
   int t=1, kk=0;
   scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
