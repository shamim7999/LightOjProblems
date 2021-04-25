/*
  Algorithm: Strongly Connected Component , DSU
*/

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
#define mx 50005
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
ld LOG(ld b, ld e){ return log(b)/log(e); }

int n, a[mx], par[mx], sz[mx], tot, ans = 1e9;
vector <int> v1[mx],v2[mx], comps[mx], vv[mx];
vector < pair<int,int> > v;
int st[mx],en[mx], cnt=1;
bitset <mx> b1,yes;


void clr()
{
	for(int i=0; i<=n; i++){
		v1[i].clear();
		v2[i].clear();
		vv[i].clear();
		st[i] = en[i] = b1[i] = yes[i] = 0;
		comps[i].clear();
	}
	v.clear();
	cnt = 1;
	ans = 1e9;
	tot = 0;
}

void make_set(int num)
{
	par[num] = num;
	sz[num] = 1;
}
int find_set(int aa)
{
	if(par[aa] == aa)
		return aa;
	return par[aa] = find_set(par[aa]);
}
void union_set(int aa, int bb)
{
	int A = aa, B = bb;
	aa = find_set(aa);
	bb = find_set(bb);
	if(aa == bb){
		return; 
	}
	if(sz[aa]<sz[bb])
		swap(aa, bb);
	par[bb] = aa;
	sz[aa]+=sz[bb];
}
void dfs1(int u)
{
    st[u]=cnt++; /// 11
    b1[u]=1;
    for(auto it : v1[u]){
        if(!b1[it]){
            //v.pb(it);
            b1[it]=1;
            dfs1(it);
        }
    }
    //b1[u]=1;
    en[u]=cnt++;
}

void dfs2(int u)
{
    if(b1[u]) return;
    b1[u]=1;
    if(comps[cnt].size() == 0){
    	comps[cnt].pb(u); /// 3
    }
    else{
    	union_set(comps[cnt][0], u);
    }
    for(auto it : v2[u]){
        if(!b1[it]){
            dfs2(it);
        }
    }
}

void dfs3(int u)
{
	if(b1[u])
		return;
	b1[u] = 1;
	for(auto child : v1[u]){
		if(find_set(child)!=find_set(u))
			vv[find_set(u)].push_back(find_set(child));
			dfs3(child);
	}
}

void dfs4(int u)
{
	if(b1[u])
		return;
	b1[u] = 1;
	int tem = 0;
	for(auto child : vv[u]){
		dfs4(child);
		tem = max(sz[child], tem);
	}
	sz[u]+=tem;

	if(sz[u]>=tot){
		if(sz[u] == tot){
			ans = min(ans, u);
		}
		else
			ans = u;
		tot = sz[u];
	}
}

void solve(int kk)
{
	clr();
    int node,edge;
    cin >> node;
    n = node;

    for(int i=0,x,y; i<node; i++){
    	cin >> x >> y, v1[x].pb(y), v2[y].pb(x), yes[x]=1, yes[y]=1;
    	make_set(x);
    	make_set(y);
    }
    for(int i=0; i<=node; i++){
        if(!b1[i] && yes[i]){
            dfs1(i);
        }
    }
    for(int i=0; i<=node; i++){
        if(b1[i] && yes[i]){
            v.pb({en[i],i});
        }
    }
    sort(v.begin(),v.end(), greater<>());

    b1.reset();
    cnt=1;
    for(auto it : v){
        if(!b1[it.se] && yes[it.se]){
            dfs2(it.se);
            ++cnt;
        }
    }

    b1.reset();
    for(int i=1; i<=node; i++){
    	if(!b1[i])
    		dfs3(i);
    }
    b1.reset();
    for(int i=1; i<=node; i++){
    	if(!b1[i])
    		dfs4(i);
    }
    cout <<"Case " << kk << ": " << ans << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
