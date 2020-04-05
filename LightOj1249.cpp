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

ld formula(ld a, ld b, ld c)
{
	ld cc = (((a*a)+(b*b))-(c*c))/(2.0*a*b);
	return cc;
}

void solve(int kk)
{
	int n;
	scanf("%d", &n);
    pair <ll,string> p[n];
    for(int i=0; i<n; i++){
    	ll a,b,c;
    	string s1;
    	cin >> s1;
    	scanf("%lld %lld %lld", &a, &b, &c);
    	p[i] = {a*b*c,s1};
	}
	sort(p,p+n);
	printf("Case %d: ", kk);
	if(p[0].fr == p[n-1].fr){
		printf("no thief\n");
	}
	else{
		cout << p[n-1].se << " took chocolate from " << p[0].se << "\n";
	}
    
}

int main()
{
   //fast;
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
