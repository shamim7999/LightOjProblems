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

ll tc, dp[(1<<10)+2][1006], a[12], fact[12], n, d;

ll func(ll mask, ll mod)
{
   if(mask == (1<<n)-1) return mod == 0;
   ll &ret = dp[mask][mod];
   if(ret!=-1) return ret;
   ll cc = 0;
   for(ll i=0; i<n; i++) if(!check(mask,i)) cc+=func(Set(mask,i), (mod*10+a[i])%d);
   return ret = cc;
}
void solve(ll tc)
{
    memo(dp,-1);
    ll cnt[10]={0};
    string s1;
    cin >> s1 >> d;
    n = s1.size();
    for(ll i=0; i<n; i++) a[i] = s1[i]-'0', cnt[a[i]]++;
    ll res = func(0,0);
    for(ll i=0; i<=9; i++) res/=fact[cnt[i]];
    cout << "Case " << tc << ": " << res << "\n";
}
int main()
{
   fast;
   ll t;
   fact[0]=1;
   for(ll i=1; i<=9; i++) fact[i] = i*fact[i-1];
   cin >> t;
   while(++tc<=t) solve(tc);

   return 0;
}
