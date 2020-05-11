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

int tc=1;


void solve(int kk)
{
    ld ab, ac, bc,m,n,rat;
    read(ab,ac,bc,rat);
    m = rat, n = 1.0;

    ld ans = sqrt((m)/(m+n))*ab;
    per(14);
    write("Case ", kk, ": ", ans);
    End;
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
