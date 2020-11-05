#include<bits/stdc++.h>
using namespace std;

#define mx 17

int dp[mx][(1<<17)-1], cost[mx][mx], n;

int func(int i, int mask)
{
    if(i == n)
        return 0;
    int &ret = dp[i][mask];
    if(ret!=-1)
        return ret;
    int ans=-1e9;

    for(int j=0; j<n; j++){
        bool ok = (mask & (1<<j));
        if(ok){
            ans = max(ans, cost[i][j] + func(i+1, (mask ^ (1<<j))));
        }
    }
    return ret = ans;
}

void solve(int tc)
{
    memset(dp, -1, sizeof dp);
    
    cin >> n;
    
    //swap(r, c);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> cost[i][j];
    }
    cout << "Case " << tc << ": " << func(0, (1<<n)-1) << "\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
    return 0;

}
