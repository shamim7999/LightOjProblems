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

ll n,k,w,kk, a[110], dp[105][105];

ll func(ll i, ll moves)
{
    if(i>=n || moves > k) return 0;
    ll &ret=dp[i][moves];
    if(ret!=-1) return ret;

    ll a1=1, a2=1,x=i+1;
    for(ll j=i+1; j<n; j++){
        if(abs(a[i]-a[j])<=w) a1++;
        else{
            x=j;
            break;
        }
    }
    a1+=func(x,moves+1);
    a2=func(i+1,moves);
    return ret=max(a1,a2);
}

void solve()
{
    scanf("%lld %lld %lld", &n, &w, &k);
    for(ll i=0,x; i<n; i++) cin >> x >> a[i]; /// No need to use X-Axis, We only have to deal with Y-Axis.
    sort(a,a+n);
    memo(dp,-1);
    printf("Case %lld: %lld\n", ++kk, func(0,1));

}

int main()
{
   ll t;
   scanf("%lld", &t);
   while(t--) solve();
   return 0;
}
