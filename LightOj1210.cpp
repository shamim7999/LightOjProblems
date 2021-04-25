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
#define mx 20005
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
int st[mx],en[mx], cnt=1, in[mx], out[mx];
bitset <mx> b1,yes;


void clr()
{
    for(int i=0; i<=n; i++){
        v1[i].clear();
        v2[i].clear();
        vv[i].clear();
        in[i] = 0, out[i] = 0;
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
    
    for(auto child : vv[u]){
        dfs4(child);
    }
}

void solve(int kk)
{
    clr();
    int node,edge, cn = 0;
    cin >> node >> edge;
    n = node;

    for(int i=0,x,y; i<edge; i++){
        cin >> x >> y, v1[x].pb(y), v2[y].pb(x), yes[x]=1, yes[y]=1;
        //make_set(x);
        //make_set(y);
    }
    for(int i=0; i<=node; i++){
        make_set(i);
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
        if(!b1[find_set(i)]){
            ++cn;
            dfs4(find_set(i));
        }
    }
    
    //cout << find_set(2) << "\n";

    vector < int > ss;
    //set < int > ss;
    for(int i=1; i<=node; i++){
        ss.push_back(find_set(i));
        //ss.insert(find_set(i));
    }
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());


    for(auto i : ss){
        //cout << i << " ";    
        for(auto it : vv[i])
            in[it]++;
        if(!vv[i].empty())
            out[i]++;
    }
    //return;
    int a1 = 0, a2 = 0;
    for(auto it : ss){
        a1+=(in[it] == 0), a2+=(out[it] == 0);
    }
  
    ans = max(a1, a2);
    if(ss.size() == 1)
        ans = 0;
    cout << "Case " << kk << ": " << ans << "\n";

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
