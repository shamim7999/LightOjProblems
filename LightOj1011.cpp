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
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
 
ll kk,n;
ll dp[17][1<<17], a[20][20];
 
ll func(ll i, ll mask)
{
    if(i>=n) return 0;
    ll &ret = dp[i][mask];
    if(ret!=-1) return ret;
 
    ll sum=-1;
    for(ll j=0; j<n; j++) if(!check(mask,j)) sum = max(sum,a[i][j]+func(i+1,Set(mask,j)));
    return ret=sum;
}
 
void solve()
{
    scanf("%lld", &n);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            scanf("%lld", &a[i][j]);
        }
    }
    memo(dp,-1);
    printf("Case %lld: %lld\n", ++kk, func(0,0));
}
 
int main()
{
   ll t;
   scanf("%lld", &t);
   while(t--) solve();
   return 0;
}
