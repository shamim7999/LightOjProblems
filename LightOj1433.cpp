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

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    ld cc = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    return cc;
}

void solve(int kk)
{
    ld oa,ob,ab;
    ld ox,oy,ax,ay,bx,by;
    ld theta;

    cin >> ox >> oy >> ax >> ay >> bx >> by;

    oa = dist(ox,oy,ax,ay);
    ob = dist(ox,oy,bx,by);
    ab = dist(ax,ay,bx,by);

    ld hold = ((oa*oa)+(ob*ob)-(ab*ab))/(2*oa*ob);

    theta = (acos(hold));
    cout << "Case " << kk << ": ";
    cout << setprecision(12) << theta*oa << "\n";

}

int main()
{
   //fast;
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
