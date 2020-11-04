#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, k;
vector <int> v;

void solve(int tc)
{
    v.clear();
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(y);
    }
    sort(v.begin(), v.end());
    int sum=0, sz=v.size()-1;
    while(1){
        ++sum;
        int x = v[sz]-k;
        auto pos = lower_bound(v.begin(), v.end(), x)-v.begin();

        if(pos == 0)
            break;
        sz = pos-1;
        if(sz<0)
            break;
        //cout << *x << "\n";
    }
    printf("Case %d: %d\n", tc, sum);
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
