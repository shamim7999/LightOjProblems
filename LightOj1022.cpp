#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

int n, m, k;
int a[mx];
ll dp[15][15];


ll func(int prev, int cnt)
{
    if(cnt == k)
        return 1;
    
    ll &ret = dp[prev][cnt];
    
    if(ret!=-1)
        return ret;
    
    ll ans=0;

    for(int i=0; i<n; i++){
        if(cnt == 0){
            ans+=func(a[i], cnt+1);
        }
        else{
            if(abs(a[i]-prev)<=2)
                ans+=func(a[i], cnt+1);
        }
    }

    return ret = ans;
    

}

void solve(int tc)
{
    memset(dp, -1, sizeof dp);
    
    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << "Case " << tc << ": " << func(0, 0) << "\n";    
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
