#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long


ll dp1[36][2][100][2][2], marker;
ll vis[36][2][100][2][2];

string Left, Right;


ll func(ll pos, ll isSmall, ll tot,  ll prev, ll start, string &s1)
{
    if(pos>=33)
        return tot;
    ll &ret = dp1[pos][isSmall][tot][prev][start];
    ll &vv = vis[pos][isSmall][tot][prev][start];
    if(vv == marker)
        return ret;
    vv = marker;
    ll en=s1[pos]-48, a1=0, zero=0;

    if(isSmall)
        en = 1;

    for(ll i=0; i<=en; i++){
        a1+=func(pos+1, isSmall | (i<en), tot+(i == 1 && prev == 1 && start), i, start | (i>0), s1);
    }
    return ret = a1;

}

void add(string &s1)
{
    ll need = 33-s1.size();
    for(ll i=1; i<=need; i++)
        s1 = '0'+s1;
}

void clr()
{
    memset(dp1, -1, sizeof dp1);
    memset(vis, -1, sizeof vis);
}

void solve(ll tc)
{
    marker=tc;
   
    ll a;
    cin >> a;
    bitset <32> b1(a);
   
    Right = b1.to_string();
    add(Right);

    cout << "Case " << tc << ": " << func(0,0,0,0,0,Right) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    clr();


    ll t;
    cin >> t;

    for(ll i=1; i<=t; i++)
        solve(i);

    return 0;
}
