#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define nthElement(x) find_by_order(x)
#define lessThan(x) order_of_key(x)
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 2000014
#define mod 1000000007
#define fr first
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define trailingZero(x) __builtin_ctz(x)
#define len(ele) (ele).size()
#define tol 0.000001
 
template<typename... T> void get(T&... args) { ((cin >> args), ...); }
 
template<typename... T> void Get(T&... args){ ((getline(cin,args)), ...); }
 
template<typename... T> void print(T&&... args) { ((cout << args << ""), ...); }
 
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
ld rad(ld x) {  return ((ld)PI*x)/180.0; }
 
/// Code Starts From Here.............................................///
 
struct hello
{
    ld x,y,z;
    hello()
    {
        x = y = z = 0;
    }
}p[3];
 
int tc=1, n, k;
/// p[2] er change nai
ld dis(hello p1, hello p2)
{
    ld aa,bb,cc;
    aa = (p1.x-p2.x)*(p1.x-p2.x);
    bb = (p1.y-p2.y)*(p1.y-p2.y);
    cc = (p1.z-p2.z)*(p1.z-p2.z);
 
    return sqrtl(aa+bb+cc);
}
 
void func()
{
    ld left = dis(p[0],p[2]), right = dis(p[1],p[2]);
    int yo=200;
 
    while(yo--){
        hello midFromLeft, midFromRight;
        midFromLeft.x = p[0].x+(p[1].x-p[0].x)/3.0;
        midFromLeft.y = p[0].y+(p[1].y-p[0].y)/3.0;
        midFromLeft.z = p[0].z+(p[1].z-p[0].z)/3.0;
 
        midFromRight.x = p[1].x+(p[0].x-p[1].x)/3.0;
        midFromRight.y = p[1].y+(p[0].y-p[1].y)/3.0;
        midFromRight.z = p[1].z+(p[0].z-p[1].z)/3.0;
 
 
        left = dis(midFromLeft,p[2]);
        right = dis(midFromRight,p[2]);
 
        if(left<right)
            p[1]=midFromRight;
        else
            p[0]=midFromLeft;
 
 
    }
    per(14);
    ld ans = min({left,right,(left+right)/2.0});
    cout << ans << "\n";
 
}
 
void solve(int kk)
{
 
    for(int i=0; i<3; i++)
        cin >> p[i].x >> p[i].y >> p[i].z;
 
    printf("Case %d: ", kk);
    func();
}
 
int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   //fast;
   //calc();
   int kk=0;
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);
 
   return 0;
}
