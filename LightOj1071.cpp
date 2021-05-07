#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 105
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx][mx], r, c, dp[100][100][100], vis[100][100][100];
int ii;

bool ok(int x, int y)
{
	return (x>=0 && x<r && y>=0 && y<c);
}

int func(int x1, int y1, int x2, int y2)
{
	if(!ok(x1, y1) || !ok(x2, y2) || x1 == x2 || y1 == y2)
		return 0;
	int a1 = 0, xx = a[x1][y1], yy = a[x2][y2];
	xx+=yy;
		
	int &ret = dp[x1][y1][x2], &vv = vis[x1][y1][x2];

	if(vv == ii)
		return ret;
	vv = ii;
	
	a1 = max(a1, xx+func(x1+1, y1, x2+1, y2));
	a1 = max(a1, xx+func(x1+1, y1, x2, y2+1));
	a1 = max(a1, xx+func(x1, y1+1, x2+1, y2));
	a1 = max(a1, xx+func(x1, y1+1, x2, y2+1));
	

	return ret = a1;
}

void solve(int kk)
{
	++ii;
    cin >> r >> c;
    for(int i=0; i<r; i++){
    	for(int j=0; j<c; j++)
    		cin >> a[i][j];
    }

    int mm = func(0, 1, 1, 0)+a[0][0]+a[r-1][c-1];
    cout << "Case " << kk << ": " << mm << "\n";

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
