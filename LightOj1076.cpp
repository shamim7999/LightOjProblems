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
#define mx 1005
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

template <typename T>
void in(T& args)
{
    ((freopen(args, "r", stdin)));
}

template <typename T>
void out(T& args)
{
    ((freopen(args, "w", stdout)));
}

template<typename... T>
void read(T&... args)
{
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args)
{
    ((cout << args << ""), ...);
}

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

/// Code Starts From Here.............................................///

int tc=1, m, n;
ll vessel[mx];

bool okay(ll capacity)
{
    int cnt=1;
    ll temp=0;
    for(int i=0; i<n; i++){
        if(temp+vessel[i]<=capacity) temp+=vessel[i];
        else temp=vessel[i], ++cnt;
    }
    //cout << "   cnt ----> " << cnt << "\n";
    return (cnt <= m);
}

void solve(int kk)
{
    ll hi=0, lo=0, ans=0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%lld", &vessel[i]);
        hi+=vessel[i];
        lo = max(vessel[i], lo);
    }
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        //write("lo = ", lo, ",      hi = ", hi, ",     mid = ", mid);
        okay(mid) ? (ans=mid, hi=mid-1) : (lo = mid+1);
    }
    printf("Case %d: %lld\n", kk, ans);
}

int main()
{
    //in("text.txt");
    //out("text2.txt");

   //fast;

   //calc();
   int kk=0;
   //read(tc);
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
