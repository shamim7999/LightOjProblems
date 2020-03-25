#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(int n, int pos){ return (n&(1<<pos)); }
bool Set(int n, int pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

void solve(int kk)
{
    ll st,en;
    scanf("%lld %lld", &st, &en);

    ll a1=0, a2=0, e1=0, e2=0;

    e1 = (en-1)%3;
    a1 = (en-1)/3;

    a1 = a1*2+e1;
    if(st!=1) --st;
    e2 = (st-1)%3;
    a2 = (st-1)/3;

    a2 = a2*2+e2;

    printf("Case %d: %lld\n", kk, a1-a2);
}

int main()
{
   int t=1,kk=0;
   scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
