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
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))

unordered_map <char,ll> mp;
ll b,k,n,tc,dp[(1<<16)+20][22], vis[(1<<16)+20][22], a[12];
string s1;

ll func(ll mask, ll mod)
{
    if(mask == (1<<n)-1) return mod == 0;
    ll &ret = dp[mask][mod], &vv = vis[mask][mod];
    if(vv == tc) return ret;
    vv = tc;
    ll cc = 0;

    for(ll i=0; i<n; i++){
        if(!check(mask,i)) cc+=func(Set(mask,i),(mod*b+mp[s1[i]])%k);
    }
    return ret = cc;
}

void solve(ll tc)
{
    cin >> b >> k >> s1;
    n = s1.size();
    cout << "Case " << tc << ": " << func(0,0) << "\n";
}

int main()
{
   fast;
   memo(dp,-1);
   string genjam = "0123456789ABCDEF";
   for(ll i=0; genjam[i]!=0; i++) mp[genjam[i]]=i;
   ll t;
   cin >> t;
   while(++tc<=t) solve(tc);

   return 0;
}
