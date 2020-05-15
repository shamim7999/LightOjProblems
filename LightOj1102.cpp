/// First learn Bar and Star method
/// https://www.youtube.com/watch?v=GtpY01vhAPc

#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 8005
#define mod 1000000007
#define fr first
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define len(ele) (ele).size()

template<typename... T> void read(T&... args) { ((cin >> args), ...); }

template<typename... T> void Read(T&... args){ ((getline(cin,args)), ...); }

template<typename... T> void write(T&&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

/// Code Starts From Here.............................................///

int tc=1;
ll fact[2000005];


ll BigMod(ll x, unsigned ll y)
{
    ll res = 1;

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll ModInverse(ll n){return BigMod(n,mod-2)%mod;}

void calc()
{
    fact[0]=1;
    for(int i=1; i<=2e6; i++){
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
    }

}

void solve(int kk)
{
    int n,r, home;
    ll ans=0;
    scanf("%d %d", &n, &r);
    int kop = r-1;
    home = n+kop;
    /// find homeCkop
    ll aa = fact[home], bb = fact[home-kop], cc = fact[kop];
    cc = ((cc%mod)*(bb%mod))%mod;
    ans = ((aa%mod)*ModInverse(cc))%mod;
    printf("Case %d: %lld\n", kk,ans);
}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   //fast;
   calc();
   int kk=0;
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
