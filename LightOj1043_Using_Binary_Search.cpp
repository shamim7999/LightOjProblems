#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k;

ld Area(ld AB, ld BC, ld AC, ld x)
{
    ld y = (AC*x)/AB;
    ld z = (BC*x)/AB;

    ld s = (x+y+z)/2.0;
    ld area1 = sqrtl(s*(s-x)*(s-y)*(s-z));
    s =  (AB+BC+AC)/2.0;
    ld area2 = sqrtl(s*(s-AC)*(s-BC)*(s-AB));
    ld trapArea = area2 - area1;

    return (area1 / trapArea);

}

void solve(int kk)
{
    ld AB, BC, AC, rat;
    cin >> AB >> AC >> BC >> rat;
    ld l = 0, r = AB, ans = 0;
    for(int i=1; i<200; i++){
        ld mid = (l+r)/2.0;
        ld tot = Area(AB, BC, AC, mid);
        if(tot-rat > 0)
            r = mid;
        else
            l = mid;
    }
    cout << "Case " << kk << ": " << setprecision(18) << l << "\n";

}   

int32_t main()
{
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
