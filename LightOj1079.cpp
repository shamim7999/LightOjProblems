#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double
#define tol 0.0000001
int ii, n, a[104];
double pi, dp[104][10004], pp[104];
int vis[104][10004];



double func(int pos, int taka)
{
    if(pos > n){
        if(taka == 0){
            return 1;
        }
        return 0;
    }
    double &ret = dp[pos][taka];
    int &vv = vis[pos][taka];
    if(vv == ii)
        return ret;
    vv = ii;

    double a1 = 0, a2 = 0;

    if(taka - a[pos]>=0){
        a1 = pp[pos]*func(pos+1, taka-a[pos]);
    }
    a2 = func(pos+1, taka);

    return ret = max(a1, a2);

}

void solve(int kk)
{
    ++ii;
    cin >> pi >> n;
    pi = 1-pi;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> pp[i];
        pp[i] = 1-pp[i];
    }
    int mm = 0;
    
    for(int i=10000; i>=0; i--){
        double ff = func(1, i);
        if((ff-pi)<0){
            continue;
        }
        mm = i;
        break;
    }
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
