#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 10009
#define mod 1000000007
#define fr first
#define se second
#define End cout << "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define memo(Array, val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout << fixed << setprecision(i)
#define con continue
#define all(ele) (ele).begin(), (ele).end()
#define Ones(x) __builtin_popcount(x)
#define trailingZero(x) __builtin_ctz(x)
#define len(ele) (ele).size()

template <typename... T>
void get(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void Get(T &... args) { ((getline(cin, args)), ...); }

template <typename... T>
void print(T &&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos) { return (n & (1 << pos)); }
bool Set(ll n, ll pos) { return (n | (1 << pos)); }
ld LOG(ld b, ld e) { return log(b) / log(e); }
ld rad(ld x) { return ((ld)PI * x) / 180.0; }

/// Code Starts From Here.............................................///

int tc = 1, node,edge,a,b;
int Time, in[mx], low[mx];
bitset <mx> vis, art;
vector <int> v[mx];

void dfs(int node, int par)
{
    int sons=0;
    vis[node]=1;
    in[node] = low[node] = Time;
    ++Time;
    for(auto child : v[node]){
        ++sons;

        if(child == par) con;

        if(vis[child]) low[node] = min(low[node], in[child]);

        else{
            dfs(child, node);

            if(low[child]>=in[node] && par!=-1)
                art[node]=1;

            else if(par == -1 && sons>1)
                art[node]=1;
            low[node]=min(low[node],low[child]);

        }
    }
}

void clr()
{
    for(int i=0; i<=node; i++){
        in[i] = low[i] = 0;
        v[i].clear();
    }
    art.reset();
    vis.reset();
    Time=0;
}

void solve(int kk)
{
    clr();

    scanf("%d %d", &node,&edge);

    while(edge--)
       scanf("%d %d", &a, &b), v[a].pb(b), v[b].pb(a);

    for(int i=1; i<=node; i++){
        if(!vis[i]) dfs(i,-1);
    }

    int tot=0;

    for(int i=1; i<=node; i++)
        tot+=(art[i]);

    printf("Case %d: %d\n", kk, tot);

}

int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;
    int kk = 0;
    //cin >> tc;
    scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
