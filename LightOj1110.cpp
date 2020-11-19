
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 105

string ans[mx][mx]; 
int n, m, dp[mx][mx];

void clr()
{
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++)
            ans[i][j]="", dp[i][j]=0;
    }
}

void solve(int tc)
{
    clr();
    string s1, s2, ss="";
    
    cin >> s1 >> s2;
    
    s1 = '^'+s1, s2 = '^'+s2;
    n = s1.size(), m = s2.size();

    int aa=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans[i][j] = ans[i-1][j-1]+s1[i];
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                ans[i][j] = ans[i-1][j];
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                dp[i][j] = dp[i][j-1];
                ans[i][j] = ans[i][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j];
                ans[i][j] = min(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    //reverse(ss.begin(), ss.end());
    if(ans[n-1][m-1].size() == 0)
        ans[n-1][m-1] = ":(";
    cout << "Case " << tc << ": " << ans[n-1][m-1] << "\n";


    
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    //calc();

    int t=1;
    cin >> t;

    for(int i=1; i<=t; i++)
        solve(i);

    return 0;
}
