#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], r, c, g, dp[(1<<17)+5][20], vis[(1<<17)+5][20], ii;
// int dx[]={0, 0, -1, 1, -1, 1, 1, -1};
// int dy[]={1, -1, 0, 0, 1, 1, -1, -1};

vector < pair<int,int> > v;
char s1[25][25];

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}
 
int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
 
bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

bool ok(int x, int y)
{
    return (x>=0 && x<r && y>=0 && y<c);
}

int dis(pair < int, int > &p1, pair< int, int > &p2)
{
    int a1 = abs(p1.first-p2.first), a2 = abs(p1.second - p2.second);
    return max(a1, a2);
}

int func(int mask, int pos)
{
    if(mask == (1<<n)-1)
        return dis(v[0], v[pos]);
    int &ret = dp[mask][pos], &vv = vis[mask][pos];
    if(vv == ii)
        return ret;
    vv = ii;
    int a1 = 1e9;
    for(int i=0; i<n; i++){
        if(!chk(mask, i)){
            a1 = min(a1, dis(v[pos], v[i])+func(Set(mask, i), i));
        }
    }
    return ret = a1;
}

void solve(int kk)
{
    ++ii;
    v.clear();

    cin >> r >> c;
    
    v.push_back({0, 0});

    for(int i=0; i<r; i++){
    
        for(int j=0; j<c; j++){
            cin >> s1[i][j];
            if(s1[i][j] == 'g'){
                ++g;
                v.push_back({i, j});
            }
            if(s1[i][j] == 'x')
                v[0] = {i, j};
        }
    }

    n = v.size();
    cout << "Case " << kk << ": " << func(0, 0) << "\n";
    // for(auto it : v){
    //     cout << it.first << " " << it.second << "\n";
    // }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //scanf("%d",&t);
    memset(dp, -1, sizeof dp);
    memset(vis, -1, sizeof vis);
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
    return 0;
}
