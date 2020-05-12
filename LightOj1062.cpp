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
#define tol 0.0000001

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
ld x,y,h;

ld func(ld w)
{
    ld h1 = sqrt((x*x)-(w*w));
    ld h2 = sqrt((y*y)-(w*w));

    ld m1 = (h1*h2), m2 = h1+h2;
    return (m1/m2);
}

void solve(int kk)
{
    read(x,y,h);
    ld mid=0, lo=0, hi=min(x,y), ans=0;
    //int cnt=100;
    while(abs(ans-h)>tol){
        mid = (lo+hi)/2.0;
        ans = func(mid);
        if(ans<=h){
            hi=mid;
        }
        else lo=mid;
    }
    per(14);
    write("Case ", kk, ": ", mid);
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
