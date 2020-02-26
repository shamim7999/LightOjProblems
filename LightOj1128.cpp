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

vector <int> g[mx];

int parent[mx],hold=-1;
int n,danger=-1;
int par[mx][24],level[mx], dis[mx];

void clr(){ for(int i=0; i<=n; i++) g[i].clear(), level[i]=-1; }

void dfs(int node, int baba)
{
    par[node][0]=baba, level[node] = 1+level[baba];
    for(auto it : g[node]) if(it!=baba) dfs(it,node);
}

int kth_parent(int u, int k)
{
	  int lvl = LOG(n,2);
	  for(int i=lvl; i>=0; i--){
	  	 if(dis[par[u][i]]>=0 && dis[par[u][i]]>=k) u = par[u][i];
	  }
	  return u;
}

void solve(int tc)
{
    clr();
    memo(dis,0);
    int q;
    scanf("%d %d", &n, &q);
	dis[1]=1;
    for(int i=2,n1; i<=n; i++) scanf("%d %d", &n1, &dis[i]), g[n1+1].pb(i), g[i].pb(n1+1);
    memo(par,-1);
    dfs(1,0);
    for(int j=1; j<=22; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1]!=-1) par[i][j] = par[par[i][j-1]][j-1];
            else par[i][j]=-1;
        }
    }
    printf("Case %d:\n",tc);
 	while(q--){
 		int a,k,nn;
 		
 		scanf("%d %d", &a, &k);
 		printf("%d\n", kth_parent(a+1,k)-1);
	}
}

int main()
{
   int t=1, kk=0;
   scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
