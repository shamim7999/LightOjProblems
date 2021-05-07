#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define int long long
#define mod 1000000007
#define ld long double

int n, a[mx], dp[30][160], vis[30][160], ii, x, po[30];

void calc()
{
	po[0] = 1;
	for(int i=1; i<=24; i++)
		po[i] = po[i-1]*6LL;
}

int func(int pos, int sum)
{
	if(pos>n)
		return (sum>=x);
	int &ret = dp[pos][sum], &vv = vis[pos][sum];
	if(vv == ii)
		return ret;
	vv = ii;


	int tot = 0;
	for(int i=1; i<=6; i++)
		tot+=func(pos+1, sum+i);
	return ret = tot;
}

void solve(int kk)
{
	++ii;
    cin >> n >> x;

    int tot = func(1, 0), mot = po[n];

    int gc = __gcd(tot, mot);
    cout << "Case " << kk << ": ";
    (tot != 0 && tot!=mot) ? cout << tot/gc << "/" << mot/gc << "\n" : cout << tot/mot << "\n";

}
 
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  memset(dp, -1, sizeof dp);
  memset(vis, -1, sizeof vis);
  calc();
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
