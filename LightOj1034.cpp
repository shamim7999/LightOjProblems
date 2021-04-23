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
#define mx 200005
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

vector <int> v1[mx];
vector < pair<int,int> > v;
int st[mx],en[mx], cnt=1, node,edge;
bitset <mx> b1,yes;

void dfs1(int u)
{
    st[u]=cnt++;
    b1[u]=1;
    for(auto it : v1[u]) if(!b1[it]) b1[it]=1, dfs1(it);
    en[u]=cnt++;
}

void clr()
{
    yes.reset(), b1.reset(), cnt=1, v.clear();
    for(int i=1; i<=node; i++) v1[i].clear(), st[i]=0, en[i]=0;
}

void dfs2(int u)
{
    if(b1[u]) return;
    b1[u]=1;
    for(auto it : v1[u]) if(!b1[it]) dfs2(it);
}

void solve(int kk)
{
    clr();
    //scanf("%d %d", &node, &edge);
    cin >> node >> edge;
    for(int i=0,x,y; i<edge; i++) cin >> x >> y, v1[x].pb(y), yes[x]=1, yes[y]=1;

    for(int i=0; i<=node; i++) if(!b1[i] && yes[i]) dfs1(i);

    for(int i=0; i<=node; i++) if(b1[i] && yes[i]) v.pb({en[i],i});

    sort(v.begin(),v.end(), greater<>());

    b1.reset();
    cnt=0;

    for(auto it : v) if(!b1[it.se]) dfs2(it.se), ++cnt;


    for(int i=1; i<=node; i++) cnt+=(b1[i] == 0);
    cout << "Case " << kk << ": " << cnt << "\n";
    //printf("Case %d: %d\n", kk, cnt);
}

int main()
{
    //freopen("text.txt", "r", stdin);
    fast;
	int t,kk=0;
	t=1;
	cin >> t;
	//scanf("%d", &t);
	while(++kk<=t) solve(kk);
	return 0;
}
