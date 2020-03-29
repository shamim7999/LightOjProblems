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
#define mx 200005
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
ld LOG(ld e, ld b){ return log(e)/log(b); }

int n;

bool func(string s1, ll b)
{
      int st=0;
      ll a1=0;
      if(s1[0] == '-') st=1;
      for(int i=st; s1[i]; i++){
          a1 = ((10*a1)+(ll)(s1[i]-48))%b;
      }
      return a1 == 0;
}

void solve(int kk)
{
    printf("Case %d: ", kk);
    string s1;
    ll b;
    cin >> s1 >> b;
    b = abs(b);
    n = s1.size();
    func(s1,b) ? printf("divisible\n") : printf("not divisible\n");
}

int main()
{
    int t,kk=0;
    t=1;
    scanf("%d", &t);
    while(++kk<=t) solve(kk);
}
