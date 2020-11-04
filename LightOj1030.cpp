#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mx 105
 
int n, k, a[mx], vis[mx];
 
double dp[mx];
 
double func(int pos)
{
    if(pos>n)
        return 0;
    if(pos == n)
        return a[pos];
 
    if(vis[pos])
        return dp[pos];
 
    vis[pos]=1;
   
    double a1=a[pos], by;
   
    by = min(6, n-pos);
   
    for(int i=1; i<=6; i++){
        a1 = a1+func(pos+i)/by;
    }
    return dp[pos] = a1;
 
}
 
void solve(int tc)
{
    memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", a+i);
    double aa = func(1);
    printf("Case %d: %.10lf\n", tc, aa);
 
}
 
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //calc();
    int t;
    //cin >> t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
        solve(i);
   
}
