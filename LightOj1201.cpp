#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 1005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], edge, aa, dp[mx][2], vis[mx][2], ii;
vector < int > v[mx];
bitset < mx > color;

void clr()
{
    for(int i=1; i<=n; i++){
        color[i] = 0;
        v[i].clear();
    }
}

int dfs(int node, int father, int nibo)
{
    color[node] = 1;
    int &ret = dp[node][nibo], &vv = vis[node][nibo];
    if(vv == ii)
        return ret;
    vv = ii;
    int a1 = 0, a2 = 0;
    for(auto child : v[node]){
        if(child == father)
            continue;
        if(nibo){
            a1 += max(1+dfs(child, node, 0), dfs(child, node, 1));
        }
        else{
            a1 += dfs(child, node, 1);
        }
    }
    return ret = a1;
}

void solve(int kk)
{
    clr();
    ++ii;
    cin >> n >> edge;
    for(int i=1; i<=edge; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y); v[y].push_back(x);
    }
    int ans = 0, tem;
    for(int i=1; i<=n; i++){
        if(color[i] == 0){
            ans+=max(1+dfs(i, -1, 0), dfs(i, -1, 1));
        }
    }
    cout << "Case " << kk << ": " << ans << "\n";
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  memset(dp, -1, sizeof dp);
  memset(vis, -1, sizeof vis);
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
