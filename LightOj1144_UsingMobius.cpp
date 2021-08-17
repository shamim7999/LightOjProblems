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
#define mx 1000100
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define PI acos(-1)

bitset<mx>compo;
vector<int>pr;
int phi[mx],mob[mx];

void io()
{
    freopen("E:/codings/cpp/in.in", "r", stdin);
    freopen("E:/codings/cpp/out.in", "w", stdout);
}


void seive(int n)
{
    phi[1]=mob[1]=1;
    for(int i=2; i<=n; i++){
        mob[i]=1;
        if(compo[i] == 0){
            pr.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0; j<pr.size() && i*pr[j]<=n; j++){
            compo[i*pr[j]]=1;
            if(i%pr[j]==0){
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
            else
                phi[i*pr[j]]=phi[i]*phi[pr[j]];
        }
    }
    for(auto xx : pr){
        int tem=xx*xx;
        if(tem>n)break;
        for(int j=tem; j<=n; j+=tem)
            mob[j]=0;
    }
    for(auto xx : pr){
        for(int j=xx; j<=n; j+=xx)
            mob[j]*=-1;
    }
}
void solve(int kk)
{
    int n, m;
    cin >> n >> m;
    if(n>m)
        swap(n, m);
    int ans = 0, sum = 0;
    for(int i=2; i<=n; i++){
        sum+=mob[i]*(n/i)*(m/i);
    }
    ans = (m*n)-abs(sum);
    if(n)
        ans++;
    if(m)
        ans++;
    cout << "Case " << kk << ": " << ans << "\n";
}

int32_t main()
{
   //io();
   fast;
   seive(mx-4); 
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
