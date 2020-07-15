#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100007
#define mod 1000000007
#define fr first
#define se second
#define End cout << "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define memo(Array, val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout << fixed << setprecision(i)
#define con continue
#define all(ele) (ele).begin(), (ele).end()
#define Ones(x) __builtin_popcount(x)
#define trailingZero(x) __builtin_ctz(x)
#define len(ele) (ele).size()
 
template <typename... T>
void get(T &... args)
{
    ((cin >> args), ...);
}
 
template <typename... T>
void Get(T &... args) { ((getline(cin, args)), ...); }
 
template <typename... T>
void print(T &&... args) { ((cout << args << ""), ...); }
 
bool check(int n, int pos) { return (n & (1 << pos)); }
bool Set(int n, int pos) { return (n | (1 << pos)); }
ld LOG(ld b, ld e) { return log(b) / log(e); }
ld rad(ld x) { return ((ld)PI * x) / 180.0; }
ll __lcm(ll a, ll b)
{
    ll gc = __gcd(a,b);
    return (a*b)/gc;
}
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    ld x = (x1 - x2) * (x1 - x2);
    ld y = (y1 - y2) * (y1 - y2);
    return sqrtl(x + y);
}
 
/// Code Starts From Here.............................................///
 
int tc = 1;
 
bitset <mx> color;
vector <ll> prime;
 
void sieve()
{
     for(ll i=3; i*i<mx; i+=2){
         if(!color[i]){
            for(ll j=i*i; j<mx; j+=i)
                color[j]=1;
         }
     }
     prime.pb(2);
     for(int i=3; i<mx; i+=2){
        if(!color[i] && i&1)
            prime.pb(i);
     }
 
}
 
int segSieve(ll l, ll r)
{
 
    bitset <mx> isPrime;
    int sum=0;
    if(l == 1)
        isPrime[0]=1;
    for(auto it : prime){
        if(it*it>r)
            break;
 
        ll start = (l/it)*it;
        if(start<l)
            start+=it;
        for(ll i=start; i<=r; i+=it)
            isPrime[i-l]=1;
        isPrime[start-l] = (start!=it);
 
    }
 
    for(ll i=l; i<=r; i++)
        sum+=(isPrime[i-l] == 0);
    return sum;
 
}
 
void solve(int kk)
{
    ll l,r;
    scanf("%lld %lld", &l, &r);
    printf("Case %d: %d\n", kk,segSieve(l,r));
 
 
}
 
 
int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;
    sieve();
    int kk = 0;
    //cin >> tc;
    scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);
 
    return 0;
}
