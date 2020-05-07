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
#define mx 1005
#define mod 1000000007
#define fr first
#define cti(a) (int)(a)
#define itc(a) (char)(a)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define len(ele) (ele).size()
#define tol 0.00000001
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
int tc=1;

struct hello
{
    dd x,y;
    hello(){
        x = y = 0;
    }
}p[4];

dd dis(hello a, hello b)
{
    dd aa = (a.x-b.x)*(a.x-b.x);
    dd bb = (a.y-b.y)*(a.y-b.y);

    return sqrt(aa+bb);
}

dd func()
{
    dd suru, sesh;

    suru = dis(p[0], p[2]);
    sesh = dis(p[1], p[3]);

    hello stFirstPerson, stSecondPerson, finFirstPerson, finSecondPerson;

    while(abs(sesh-suru)>tol){
        stFirstPerson.x = p[0].x+(p[1].x-p[0].x)/3.0;
        stFirstPerson.y = p[0].y+(p[1].y-p[0].y)/3.0;
        finFirstPerson.x = p[1].x+(p[0].x-p[1].x)/3.0;
        finFirstPerson.y = p[1].y+(p[0].y-p[1].y)/3.0;

        stSecondPerson.x = p[2].x+(p[3].x-p[2].x)/3.0;
        stSecondPerson.y = p[2].y+(p[3].y-p[2].y)/3.0;
        finSecondPerson.x = p[3].x+(p[2].x-p[3].x)/3.0;
        finSecondPerson.y = p[3].y+(p[2].y-p[3].y)/3.0;

        suru = dis(stFirstPerson, stSecondPerson);
        sesh = dis(finFirstPerson, finSecondPerson);

        if(suru>sesh){
            p[0]=stFirstPerson, p[2]=stSecondPerson;
        }
        else p[1]=finFirstPerson, p[3]=finSecondPerson;

    }
    return suru; /// return sesh, also is correct. Same thing!
}

void solve(int kk)
{
    for(int i=0; i<4; i++) scanf(" %lf %lf", &p[i].x, &p[i].y);

    printf("Case %d: %lf\n", kk, func());

}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   //fast;
   int kk=0;
   //cin >> tc;
   scanf(" %d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}

/// I took help from  --->  https://github.com/mazedrupok
