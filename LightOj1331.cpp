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
    ld r1,r2,r3,a,b,c, area1,area2, s;
    ld A,B,C,ang1,ang2,ang3;
    cin >> r1 >> r2 >> r3;
    a = r1+r2, b = r1+r3, c = r2+r3;
    
    s = (a+b+c)/2.0;
    
    area1 = sqrt(s*(s-a)*(s-b)*(s-c));
    
    A = formula(b,c,a);
    B = formula(a,c,b);
    C = formula(a,b,c);
	  
	ld bb = (180.0/PI);  
    ang1 = acos(A)*bb, ang2 = acos(B)*bb, ang3 = acos(C)*bb;
 
    A = (PI*r3*r3*ang1)/360.0;
    B = (PI*r2*r2*ang2)/360.0;
    C = (PI*r1*r1*ang3)/360.0;
   
    printf("Case %d: ", kk);
    cout << setprecision(12) << area1-A-B-C << "\n";
    
}

int main()
{
   //fast;
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
