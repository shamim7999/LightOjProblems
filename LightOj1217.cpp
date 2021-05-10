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

int n, a[mx+mx+5], dp[mx+mx+5], vis[mx+mx+5], ii, en;


int func(int pos)
{
    if(pos>=en)
        return 0;
    int &ret = dp[pos], &vv = vis[pos];

    if(vv == ii)
        return ret;
    vv = ii;

    int a1 = 0, a2 = 0;

    a1 = a[pos]+func(pos+2);
    a2 = func(pos+1);

    return ret = max(a1, a2);
    
}

void solve(int kk)
{
    ++ii;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=n+1, j = 1; i<=2*n; i++, j++)
        a[i] = a[j];
    
    int sum = 0, mm = 0;
    for(int i=1; i<=n; i++){
        en = i+n-1;
        sum = func(i);
        mm = max(sum, mm);
    }

    cout << "Case " << kk << ": " << mm << "\n";

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
