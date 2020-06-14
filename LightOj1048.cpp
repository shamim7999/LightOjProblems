#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1009
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

int tc = 1, k, n;
ll a[mx];

bool func(ll mid)
{
    ll sum=0;
    int id=0;
    for(int i=1; i<=n; i++){
        if(sum+a[i]<=mid) sum+=a[i];
        else{
            ++id;
            sum=a[i];
        }
    }
    ++id;
    return id<=k;
}

void solve(int kk)
{
     ll left=0, right=0;
     scanf("%d %d", &n, &k);
     ++n, ++k;
     for(int i=1; i<=n; i++)
        scanf("%lld", a+i),
        left = max(left, a[i]),
        right+=a[i];
     ll ans=0;
     while(left<right){
        ll mid = (left+right)/2;
        if(func(mid)){
            ans=mid;
            right=mid;
        }
        else
            left=mid+1;
     }
     ll sum=0;
     printf("Case %d: %lld\n", kk, ans);
     for(int i=1; i<=n; i++){
         sum+=a[i];
         if(sum>ans){
            --k;
            printf("%lld\n", sum-a[i]);
            sum=a[i];
         }
         else if((n-i+1) == k){
            --k;
            printf("%lld\n", sum);
            sum=0;
         }
     }
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
