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
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

bool okay(ll r1, ll c1)
{
    if((r1&1 && c1&1)||(r1%2 == 0 && c1%2 == 0)) return 1;
    return 0;
}

void solve(int kk)
{
    printf("Case %d: ", kk);
    ll r1,r2,c1,c2;
    scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
    bool ok1=0,ok2=0;
    ok1 = okay(r1,c1), ok2 = okay(r2,c2);
    if(ok1 == ok2){
        (abs(r1-r2) == abs(c1-c2)) ? printf("1\n") : printf("2\n");
    }
    else printf("impossible\n");

}

int main()
{
 
   int kk=0;
   
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
