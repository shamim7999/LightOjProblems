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

int tc;

bool okay(string s1)
{
    int l=0,r=s1.size()-1;
    while(l<r){
        if(s1[l]!=s1[r]) return 0;
        ++l,--r;
    }
    return 1;
}

void solve(int kk)
{
    printf("Case %d: ", kk);
    string s1;
    cin >> s1;
    okay(s1) ? printf("Yes\n") : printf("No\n");

}

int main()
{
   //fast;
   int kk=0;
   //cin >> t;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
