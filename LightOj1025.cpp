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

char s1[70];
ll dp[70][70], len,kk;

ll func(ll left, ll right)
{
    if(left>right) return 0;
    if(left == right) return 1;
    ll &ret=dp[left][right];
    if(ret!=-1) return ret;
    ll a1=0,a2=0;
    s1[left] == s1[right] ? a1=1+func(left+1,right)+func(left,right-1) : a1=func(left+1,right)+func(left,right-1)-func(left+1,right-1);
    return ret=a1;
}

void solve()
{
    scanf(" %s", s1);
    memo(dp,-1);
    len = strlen(s1);
    printf("Case %lld: %lld\n", ++kk, func(0,len-1));

}

int main()
{
   ll t;
   scanf("%lld", &t);
   while(t--) solve();
   return 0;
}
