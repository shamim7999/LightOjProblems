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
#define mx 10005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

int n, m, a[mx+5], res, ans[mx+5], cnt[mx+5];

void io()
{
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
}

void clr()
{
    for(int i=1;i<=n; i++)
        cnt[a[i]] = 0;
}

int fact(int tot, int x)
{
   int mul = 1; 
   for(int i=tot; i>x; i--){
        mul*=i;
   }
   return mul;
}

void solve(int kk)
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i], cnt[a[i]]++;

    for(int i=mx; i>=1; i--){
        int tot = 0;
        for(int j=i; j<=mx; j+=i){
            ans[i]-=ans[j];
            tot+=cnt[j];
        }
        if(tot<4)
            ans[i] = 0;
        else{
            ans[i] += fact(tot, tot-4)/24;
        }
    }
    cout << "Case " << kk << ": " << ans[1] << "\n";
    clr();

}

int32_t main()
{
   io();
   fast;
   int t = 1;
   //seive(mx-3);
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
