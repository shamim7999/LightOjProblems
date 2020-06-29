#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define mx 25
#define fr first
#define se second
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector <ll> v1,v2;
int n;
ll k, a[mx];

void set1(ll val, int idx)
{
    v1.pb(val);
    if(idx > n/2)
        return;
    set1(val, idx+1);
    set1(val+a[idx], idx+1);
    set1(val+2*a[idx], idx+1);
}


void set2(ll val, int idx)
{
    v2.pb(val);
    if(idx > n)
        return;
    set2(val, idx+1);
    set2(val+a[idx], idx+1);
    set2(val+2*a[idx], idx+1);
}

void solve(int kk)
{
    scanf("%d %lld", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%lld", &a[i]);

    set1(0, 1);
    set2(0, n/2+1);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    printf("Case %d: ", kk);
    bool ok=0;
    for(auto it : v1){
        ll sub = k-it;
        auto f = lower_bound(v2.begin(),v2.end(), sub);
        if(f!=v2.end() && *f == sub){
            ok=1;
            break;
        }
    }
    ok ? printf("Yes\n") : printf("No\n");
    v1.clear();
    v2.clear();
}


int main()
{
    int tc=0, t;
    scanf("%d", &t);
    while(++tc<=t)
        solve(tc);


   return 0;
}

// took help from,   https://turing13.wordpress.com/2016/09/13/light-oj-1235-coin-change-iv/
