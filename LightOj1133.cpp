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

int tc;

void solve(int kk)
{
    printf("Case %d:\n", kk);
    int n, k;
    scanf("%d %d", &n, &k);
    vector <ll> v;
    ll x;
    for(int i=1; i<=n; i++) scanf("%lld", &x), v.pb(x);

    while(k--){
        char ch;
        ll a;
       // scanf(" %c", ch);
       cin >> ch;
        if(ch == 'D'){
            scanf("%lld", &a);

            for(int i=0; i<n; i++) v[i]/=a;

        }
        else if(ch == 'M'){
            scanf("%lld", &a);

            for(int i=0; i<n; i++) v[i]*=a;
        }
        else if(ch == 'S'){
            scanf("%lld", &a);

            for(int i=0; i<n; i++) v[i]+=a;
        }
        else if(ch == 'R') reverse(v.begin(),v.end());
        else{
            int a1,a2;
            scanf("%d %d", &a1, &a2);
            swap(v[a1],v[a2]);

        }
    }
    printf("%d", v[0]);
    for(int i=1; i<n; i++) printf(" %d", v[i]);
    End;
}

int main()
{
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
