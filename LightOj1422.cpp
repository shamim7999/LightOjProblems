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

int n, a[mx], dp[mx][mx], vis[mx][mx], ii;

int func(int be, int en)
{
	if(be>en)
		return 0;
	int &vv = vis[be][en], &ret = dp[be][en];
	if(vv == ii)
		return ret;
	vv = ii;

	int a1 = 1+func(be+1, en), a2 = 1e9;

	for(int i=be+1; i<=en; i++){
		if(a[i] == a[be])
			a2 = min(a2, func(be+1, i)+func(i+1, en));
	}

	return ret = min(a1, a2);
}

void solve(int kk)
{
	++ii;
    cin >> n;
    for(int i=1; i<=n; i++)
    	cin >> a[i];
    cout << "Case " << kk << ": " << func(1, n) << "\n";

}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  memset(dp, -1, sizeof dp);
  memset(vis, -1, sizeof vis);

  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
