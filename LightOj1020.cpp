#include<bits/stdc++.h>
using namespace std;

#define ll long long


void solve(int tc)
{
    string s1, ans;
    
    ll tot;
    scanf("%lld", &tot);
    cin >> s1;
    if(s1 == "Alice"){
        tot%3 == 1 ? ans = "Bob" : ans = "Alice";
    }
    else{
        tot%3 == 0 ? ans = "Alice" : ans = "Bob";
    }
    printf("Case %d: ", tc);
    cout << ans << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //calc();
    int t;
    //cin >> t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
        solve(i);
    
}
