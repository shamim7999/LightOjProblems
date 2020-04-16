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

vector <int> v1[mx],v2[mx], comps[mx];
vector < pair<int,int> > v;
int st[mx],en[mx], cnt=1, tot=0, node;
bitset <mx> b1,yes;

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
    comps[cnt].pb(u); /// 3
    for(auto it : v2[u]){
        if(!b1[it]){
            dfs2(it);
        }
    }
}

void clr()
{
    for(int i=0; i<=node; i++) v1[i].clear(), v2[i].clear(), st[i]=0, en[i]=0, comps[i].clear();
    cnt=1, tot=0;
    v.clear(), b1.reset(),yes.reset();
}

void clr2(int u)
{
    if(!b1[u]) return;
    b1[u]=0;
    for(auto it : v1[u]) if(b1[it]) clr2(it);
}

void dfs3(int u)
{
    if(b1[u]) return;
    b1[u]=1;
    ++tot;
    for(auto it : v1[u]) if(!b1[it]) dfs3(it);
}

void solve(int kk)
{
    scanf("%d", &node);

    for(int i=0,x,y; i<node; i++)scanf("%d %d", &x, &y), v1[x].pb(y), v2[y].pb(x), yes[x]=1, yes[y]=1;

    for(int i=0; i<=node; i++){
        if(!b1[i] && yes[i]){
            dfs1(i);
            //--cnt;
        }
    }
    for(int i=0; i<=node; i++){
        if(b1[i] && yes[i]){
            //cout << i << " start is " << st[i] << ", end is " << en[i] << "\n";
            v.pb({en[i],i});
        }
    }
    sort(v.begin(),v.end(), greater<>());

    //for(auto it : v) cout << it.se << "\n";
    //return;

    b1.reset();
    cnt=1;
    for(auto it : v){
        if(!b1[it.se] && yes[it.se]){
            dfs2(it.se);
            ++cnt;
        }
    }

    int Maxi=0, Node=0;
    for(int i=1; i<cnt; i++){
        int xx = comps[i][0];
        clr2(xx);
        dfs3(xx);
        if(tot>Maxi){
            Maxi=tot;
            Node=xx;
        }
        else if(tot == Maxi) Node = min(Node,xx);
        tot=0;
    }
    printf("Case %d: %d\n", kk, Node);

    clr();
}

int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
	int t,kk=0;
	t=1;
	cin >> t;
	while(++kk<=t) solve(kk);
	return 0;
}
