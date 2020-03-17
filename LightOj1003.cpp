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

vector <int> v1[mx],v2[mx];
vector < pair<int,int> > v;
int st[mx],en[mx], cnt=1, node,edge;
bitset <mx> b1,yes;
unordered_map <string,int> mp;

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
    //comps[cnt].pb(u); /// 3
    for(auto it : v2[u]){
        if(!b1[it]){
            dfs2(it);
        }
    }
}

void clr()
{
    for(int i=0; i<=node; i++) v1[i].clear(), v2[i].clear(), st[i]=0, en[i]=0;
    mp.clear(),b1.reset(),yes.reset(), cnt=1, v.clear();
}

void solve(int kk)
{
    clr();

    int k=1;
    cin >> edge;

    for(int i=0; i<edge; i++){
        string x,y;
        cin >> x >> y;
        if(mp.find(x) == mp.end()) mp[x]=k, ++k;
        if(mp.find(y) == mp.end()) mp[y]=k, ++k;
        int aa = mp[x], bb = mp[y];


        v1[aa].pb(bb), v2[bb].pb(aa), yes[aa]=1, yes[bb]=1;
    }
    node=k-1;
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

    b1.reset();
    cnt=1;
    for(auto it : v){
        if(!b1[it.se] && yes[it.se]){
            dfs2(it.se);
            ++cnt;
        }
    }
    --cnt;
    printf("Case %d: ", kk);
    cnt == node ? printf("Yes\n") : printf("No\n");
}

int main()
{
    //fast;
	int t,kk=0;
	t=1;
	scanf("%d", &t);
	while(++kk<=t) solve(kk);
	return 0;
}
