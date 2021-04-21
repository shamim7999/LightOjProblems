#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], r, c, g, dp[(1<<17)+5][20], vis[(1<<17)+5][20], ii;
// int dx[]={0, 0, -1, 1, -1, 1, 1, -1};
// int dy[]={1, -1, 0, 0, 1, 1, -1, -1};

int cost[25][25];

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}
 
int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
 
bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

int func(int mask, int pos)
{
    if(mask == (1<<n)-1)
        return 0;
    int &ret = dp[mask][pos], &vv = vis[mask][pos];
    if(vv == ii)
        return ret;
    vv = ii;

    int a1 = 0;

    for(int i=0; i<n; i++){
        if(!chk(mask, i)){
            a1=max(a1, cost[pos][i]+func(Set(mask, i), pos+1));
        }
    }
    return ret = a1;
    
}

void solve(int kk)
{
    ++ii;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }
    }
    
    cout << "Case " << kk << ": " << func(0, 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //scanf("%d",&t);
    memset(dp, -1, sizeof dp);
    memset(vis, -1, sizeof vis);
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
    return 0;
}
