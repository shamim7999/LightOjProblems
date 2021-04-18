// Special Thanks to Ashraful Haque(CF - ash98) & Rayhan Dhruboo Vai(CF - Kosai)

#include<bits/stdc++.h>
using namespace std;

const int mx = 100005;

#define mod 100000007

int dp[2][25000], pre[2][25000];

int func(int x)
{
    if(x>=mod)
        x-=mod;
    if(x<0)
        x+=mod;
    return x;
}

void solve(int kk)
{
    int n, k, s;
    cin >> n >> k >> s;

    memset(dp, 0, sizeof dp);
    memset(pre, 0, sizeof pre);

    /// base case
    dp[(n+1) & 1][0] = pre[(n+1) & 1][0] = 1;
    //////
    for(int i=1; i<=s; i++)
        dp[(n+1) & 1][i] = 0, pre[(n+1) & 1][i] = 1;

    for(int i=n; i>=1; i--){
        dp[i & 1][0] = pre[i & 1][0] = 0;

        for(int w=1; w<=s; w++){
        
            if(w-k-1>=0)
                dp[i & 1][w] = func(pre[(i+1) & 1][w-1] - pre[(i+1) & 1][w-k-1]);
            else
                dp[i & 1][w] = func(pre[(i+1) & 1][w-1]);
            
            pre[(i & 1)][w] = func(pre[i & 1][w-1]+dp[(i & 1)][w]);
        }
    }

    cout << "Case " << kk << ": " << dp[1][s] << "\n";

}

int main()
{
    //freopen("E://Codings//CPP//input.in", "r", stdin);
    //freopen("E://Codings//CPP//output.in", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i=1; i<=t; i++)
      solve(i);

}
