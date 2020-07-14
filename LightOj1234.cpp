#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 200
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
const int N=1e8+10;
ld a[1000006];
void calc()
{
    ld ans=0;
    for(int i=1; i<N; i++){
        ans+=(1.0/(ld)i);
        if(i%100 == 0)
            a[i/100]=ans;
    }

}

void solve(int kk)
{
    int en, st;
    scanf("%d", &en);
    st = en/100;
    ld ans=a[st];
    for(int i=(st*100)+1; i<=en; i++)
        ans+=(1.0/(ld)i);
    per(14);
    cout << "Case " << kk << ": " << ans << "\n";

}


int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;
    calc();
    int kk = 0;
    //cin >> tc;
    scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
