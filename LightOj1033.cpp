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
#define PI acos(-1)

char s1[110];
ll dp[110][110],vis[110][110],n;
ll a;

ll func(ll left, ll right)
{
    if(left>n || right<0) return 1e9;
    if(left == right) return 0;
    if(left+1 == right) return s1[left] != s1[right];
    ll &ret = dp[left][right], &vv=vis[left][right];
    if(vv == a) return ret;
    vv = a;
    ll a1=0,a2=0;
    s1[left] == s1[right] ? a1=func(left+1,right-1) : a2=min(func(left+1,right),func(left,right-1))+1;
    return ret=a1+a2;
}

void solve(ll a)
{
   scanf(" %s", s1);
   n = strlen(s1);
   printf("Case %lld: %lld\n", a, func(0,n-1));
}

int main()
{
   ll t;
   scanf("%lld", &t);
   memo(dp,-1);
   while(++a<=t) solve(a);
   return 0;
}
