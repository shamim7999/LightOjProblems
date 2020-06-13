#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 200005
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
 
bool check(ll n, ll pos) { return (n & (1 << pos)); }
bool Set(ll n, ll pos) { return (n | (1 << pos)); }
ld LOG(ld b, ld e) { return log(b) / log(e); }
ld rad(ld x) { return ((ld)PI * x) / 180.0; }
 
/// Code Starts From Here.............................................///
 
int tc = 1;
ll a[mx], pre[mx];
 
void solve(int kk)
{
    ld a,b,r,S,x;
    char ch;
    get(a,ch,b);
    r = sqrtl(a*a+b*b)/2;
    ld ang;
    ang = acos((2*r*r-b*b)/(2.0*r*r));
    S = r*ang;
    x = 200.0/(a+S);
    per(14);
    print("Case ", kk, ": ", a*x, " ", b*x);
    End;
 
}
 
int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;
    int kk = 0;
    //cin >> tc;
    scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);
 
    return 0;
}
