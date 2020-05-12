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
#define mx 5000000
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

int phi[mx+2];
ull ans[mx+2];

int tc=1;

void ETF1()
{
    for(int i=2; i<=mx; i++)
        phi[i] = i;

    for(int i =2; i<=mx; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=mx; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    ans[1]=0;
    for(int i=2; i<=mx; i++){
        ans[i]=phi[i];
        ans[i]*=phi[i];
        ans[i]+=ans[i-1];
    }
}

void solve(int kk)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case %d: %llu\n", kk, ans[b]-ans[a-1]);
}
int main()
{
   //in("text.txt");
   //out("text2.txt");
   ETF1();
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);
   return 0;
}
