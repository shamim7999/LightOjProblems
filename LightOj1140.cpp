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
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

ll dp[15][2][15][2];
const ll mpos=13;
char s1[20];

ll func(ll pos, ll isSmall, ll zero, ll isStart)
{
	if(pos == mpos) return zero;
	ll &ret = dp[pos][isSmall][zero][isStart];
	if(ret!=-1) return ret;

	ll a1=0, start = 0, End=9;
	if(!isSmall) End = s1[pos]-48;

	for(ll i=start; i<=End; i++){
        ll Small = isSmall | (i<End);
        ll temp  = zero+(i == 0 && isStart);
        ll Start = isStart | (i!=0);

        a1+=func(pos+1,Small,temp, Start);

	}
	return ret = a1;

}

void convert(ll N)
{
   for(ll i=0; i<mpos; i++){
       s1[i] = (N%10)+48;
       N/=10;
   }
   reverse(s1,s1+mpos);
   s1[mpos]=0;
}

void solve(ll tc)
{
    memo(dp,-1);
    ll m,n;
    cin >> m >> n;
    convert(n);
    n = func(0,0,0,0)+1;

    if(m!=0){
        memo(dp,-1);
        --m;
        convert(m);
        m = func(0,0,0,0)+1;
    }
    cout << "Case " << tc << ": " << n-m << "\n";
}

int main()
{
   //fast;
   ll t,tc=0;
   cin >> t;
   while(++tc<=t) solve(tc);
   return 0;
}
