#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 200100
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

int n, m, a[40];

void io()
{
    freopen("E:/codings/cpp/in.in", "r", stdin);
    freopen("E:/codings/cpp/out.in", "w", stdout);
}
int res = 0;

void func(int pos, int cnt, int lc)
{
    if(lc>n)
        return;
    if(pos == m){
        if(cnt == 0)
            return;
        cnt&1 ? res+=(n/lc) : res-=(n/lc);
        return;
    }
    func(pos+1, cnt+1, ((lc*a[pos])/__gcd(lc, a[pos])));
    func(pos+1, cnt, lc);
}

void solve(int kk)
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    res = 0;
    func(0, 0, 1);
    cout << "Case " << kk << ": " << n-res << "\n";
}

int32_t main()
{
   //io();
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
