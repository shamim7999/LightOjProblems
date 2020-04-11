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
    ll a[n+5];
    a[0]=2;
    for(int i=1; i<=n; i++) scanf("%lld", a+i);
    int sum=0;
    for(int i=0; i<=n; i++){
        if(i+1<=n){
            ll sub = ceil((a[i+1]-a[i])/5.0);
            sum+=sub;
        }
    }
    printf("Case %d: %d\n", kk, sum);

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
