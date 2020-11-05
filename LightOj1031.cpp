#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

ll dp[mx][mx], a[mx];
int n;

ll func(int st, int en)
{   
    if(st>en)
        return 0;
    if(st == en)
        return a[st];
    ll &ret = dp[st][en];
    if(ret!=-1)
        return ret;
    ret = -1e9;

    ll a1=0;

    for(int i=st; i<=en; i++){
        a1+=a[i];
        ret = max(ret, a1-func(i+1, en));
    }
    a1=0;
    for(int i=en; i>=st; i--){
        a1+=a[i];
        ret = max(ret, a1-func(st, i-1));
    }

    return ret;

}

void solve(int tc)
{
    memset(dp, -1, sizeof dp);
    
    cin >> n;
    
    //swap(r, c);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    cout << "Case " << tc << ": " << func(1, n) << "\n";

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
