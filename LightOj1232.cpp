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
#define mod 100000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define PI acos(-1)

ll dp[10004], a[10004], n;

ll func(ll k)
{
    dp[0]=1;
    for(ll i=0; i<n; i++){
        for(ll j=a[i]; j<=k; j++) dp[j] = (dp[j]%mod+dp[j-a[i]]%mod)%mod;
    }
    return dp[k];
}
void solve(ll e)
{
    ll k;
    memo(dp,0);
    scanf("%lld %lld", &n, &k);
    for(ll i=0; i<n; i++) scanf("%lld", a+i);
    printf("Case %lld: %lld\n", e, func(k));
}
int main()
{
   ll t,c=0;
   scanf("%lld", &t);
   while(++c<=t) solve(c);
   return 0;
}
