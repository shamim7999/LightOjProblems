#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define uint unsigned long long
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
bool check(int n, int pos){ return (n&(1<<pos)); }
bool Set(int n, int pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
 
vector <int> v1,v2;
int dp[51][51],n, kk, vis[51][51];
 
int func(int i, int j)
{
    if(i>=n || j>=n) return 0;
    int &ret = dp[i][j], &vv = vis[i][j];
    if(vv == kk) return ret;
    vv = kk;
    int a1 = 0, a2 = 0, a3=0, a4=0,sum=0;
 
    if(v1[i]>v2[j]) a1 = 2+func(i+1,j+1);
    else if(v1[i] == v2[j]) a2 = 1+func(i+1,j+1);
    a3 = func(i,j+1);
    a4 = func(i+1,j);
    //printf("kkkkk\n");
    sum += max({a1,a2,a3,a4});
 
    return ret = sum;
 
}
 
void solve()
{
    //int n;
    int x,sum=0;
 
    v1.clear(),v2.clear();
 
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &x), v1.pb(x);
    for(int i=0; i<n; i++) scanf("%d", &x), v2.pb(x);
 
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
 
    printf("Case %d: %d\n", kk, func(0,0));
}
 
int main()
{
   int t=1;
   //cin >> t;
   memo(dp,-1);
   scanf("%d", &t);
   while(++kk<=t) solve();
 
   return 0;
}
