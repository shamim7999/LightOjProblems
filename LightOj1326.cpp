#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 1005
#define mod 10056

int dp[mx][mx], ans[mx];

int ncr(int N, int R)
{
    ///
    if(N == R)
        return 1;
    if(R == 1)
        return N;
    int &ret = dp[N][R];
    if(ret!=-1)
        return ret;
    return ret = ( ncr(N-1, R-1)%mod + ncr(N-1, R)%mod ) % mod; 
}

int func(int n)
{
    if(n<=0)
        return 1;

    int &ret = ans[n];
    if(ret!=-1)
        return ret;

    int a1=0, a2=0;

    for(int i=1; i<=n; i++){
        a1 += (ncr(n, i)*func(n-i)) %mod;
        a1%=mod;
        //a1 = (a1%mod + a2%mod)%mod;
    }

    return ret = a1;
}

void solve(int tc)
{   
    int n;
    
    cin >> n;
    cout << "Case " << tc << ": " << func(n) << "\n";    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //calc();
    memset(dp, -1, sizeof dp);
    memset(ans, -1, sizeof ans);
    int t=1;
    cin >> t;
    
    for(int i=1; i<=t; i++)
        solve(i);

    return 0;
}
