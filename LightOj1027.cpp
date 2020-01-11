clude<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 200005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define PI acos(-1)
 
void solve(ll a)
{
   ll n,sum=0,pos=0,GCD,x;
   scanf("%lld", &n);
   while(n--) scanf("%lld", &x), sum+=abs(x), pos+=(x>0);
   GCD = __gcd(sum,pos);
   pos == 0 ? printf("Case %lld: inf\n", a) : printf("Case %lld: %lld/%lld\n", a, sum/GCD, pos/GCD);
}
 
int main()
{
   ll t,a=0;
   scanf("%lld", &t);
   while(++a<=t) solve(a);
   return 0;
}
