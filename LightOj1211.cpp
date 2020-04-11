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
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

void solve(int kk)
{
    int n;
    scanf("%d", &n);
    ll x1,x2,y1,y2,z1,z2,x,y,z;
    ll ox=-1, oy=-1, oz=-1, ax=1e10, ay=1e10, az=1e10;

    while(n--){
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
        ox = max(ox,x1), oy = max(oy,y1), oz = max(oz,z1);
        ax = min(ax,x2), ay = min(ay,y2), az = min(az,z2);
    }
    x = ax-ox, y = ay-oy, z = az-oz;
    printf("Case %d: ", kk);
    if(x<0 || y<0 || z<0){
        puts("0");
        return;
    }

    printf("%lld\n", x*y*z);

}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   //fast;
   int kk=0;
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
