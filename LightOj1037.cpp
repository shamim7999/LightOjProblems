#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 16
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], dp[(1<<mx)+mx], vis[(1<<mx)+mx], ii;
char mat[mx][mx];

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
 

int ff(int x, int y)
{
    x = (x/y)+(x%y!=0);
    return x;
}

int func(int mask)
{
    if(mask == (1<<n)-1)
        return 0;
    int &ret = dp[mask], &vv = vis[mask];

    if(vv == ii)
        return ret;
    vv = ii;

    int a1 = 1e9;
    
    for(int i=0; i<n; i++){
        if(!chk(mask, i)){
            int mm = 1;
            for(int j=0; j<n; j++){
                if(chk(mask, j))
                    mm = max(mm, mat[j][i]-'0');
            }

            int rr = ff(a[i], mm); // koyta bullet lagse?
            a1 = min(a1, rr+func(Set(mask, i)));
        }
    }

    return ret = a1;
}

void solve(int kk)
{
    ++ii;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> mat[i][j];
    }
    cout << "Case " << kk << ": " << func(0) << "\n";

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
