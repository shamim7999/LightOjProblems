#include "bits/stdc++.h"
using namespace std;
#define int long long
#define mod 100000007
const int inf = 1e18;
int ii, dp[105][10005];

int add(int &a, int &b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}

signed main(){
    //freopen("in.txt", "r", stdin);
	int n, lim, t;
	cin >> t;

	while(t--){
        cin >> n >> lim;

	int v[n+10];

	for(int i=1; i<=n; i++)
        cin >> v[i];
    
    memset(dp, 0, sizeof dp);
   
        dp[n+1][0]=1;  ///Base case
        dp[n+1][lim] = 0;  ///Base case
    

    for(int i=n; i>=1; i--){
        for(int s=0; s<=lim; s++){
            dp[i][s] = 0; /// Base Case
            int op1=0, op2=0;

            op1 = dp[i+1][s];
            if((s-v[i])>=0){
                op2 = dp[i][s-v[i]];
            }
            dp[i][s] = add(op1, op2);
        }
    }


    cout << "Case " << ++ii << ": " << dp[1][lim] << "\n";

	}
	return 0;
}
