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
ld LOG(ld e, ld b) { return log(e) / log(b); }
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

map <ll,int> cnt;

void primeFactors(ll n)
{
	while (n%2 == 0)
	{
		cnt[2]++;
		n = n/2;
	}

	for (ll i = 3; i <= sqrtl(n); i = i+2)
	{

		while (n%i == 0)
		{
			cnt[i]++;
			n = n/i;
		}
	}
	if (n > 2)
		cnt[n]++;
}


ll func(ll n)
{
    ll f=1;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            ll div = n/i;
            if(i&1)
                f = max(f, i);
            if(div&1)
                f = max(f, div);
        }
    }
    return f;
}

void solve(int kk)
{
    cnt.clear();
    ll x;
    scanf("%lld", &x);
    printf("Case %d: ", kk);
    primeFactors(abs(x));
    bool allEqual=1;
    vector <int> v;
    ll hold;
    for(auto it : cnt)
        v.pb(it.se);
    sort(all(v));

    //for(auto it : v)
    //    cout << it << " ";
    //return;
    //End;


    if(x == 1 || x == 0){
        printf("1\n");
        return;
    }
    bool yes=1;
    for(auto it : v){
        if(it%v[0]!=0){
            yes=0;
            break;
        }
    }
    //cout << "YES is: " << yes << "\n";
    //return;
    if(yes){
        hold=v[0];
        if(x<0){
            if(v[0]%2 == 0 && (v[0]/2)&1)
                hold=v[0]/2;
            else
                hold=func(v[0]);
        }

        printf("%lld\n", hold);
        return;
    }
    yes=1;
    for(auto it : v){
        if(it%3!=0){
            yes=0;
            break;
        }
    }
    if(yes){
        printf("3\n");
        return;
    }
    yes=1;
    for(auto it : v){
        if(it%2!=0){
            yes=0;
            break;
        }
    }
    if(yes){
        hold=2;
        if(x<0){
            hold=1;
        }
        printf("%lld\n", hold);
        return;
    }
    printf("1\n");


}

int main()
{
    freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;

    int kk = 0;
    //cin >> tc;
    scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
