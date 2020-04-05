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
    ld ax,ay,bx,by,cx,cy,dx,dy,ox,oy,area1,area2;
    
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    ox = (ax+cx)/2.0, oy = (ay+cy)/2.0;
    
    dx = (2*ox)-bx, dy = (2*oy)-by;
    
    area1 = abs((ax*(by-cy)-ay*(bx-cx)+(bx*cy-by*cx))*.5);
    area2 = abs((ax*(cy-dy)-ay*(cx-dx)+(cx*dy-dx*cy))*.5);
    
    printf("Case %d: ", kk);
    cout << setprecision(12) << dx << " " << dy << " " << area1+area2 << "\n";
    
}

int main()
{
   //fast;
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
