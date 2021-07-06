#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define int long long
#define mod 1000000007
#define ld long double

int n, a[mx];

bool func(int x)
{
    for(int i=1; i<=n; i++){
        int need = a[i]-a[i-1];
        if(need>x)
            return 0;
        if(need == x && x>0)
            --x;
    }
    return 1;
}

void solve(int kk)
{
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int left = 1, right = 1e9;
    while(left<=right){
        int mid = (right+left)/2;
        if(func(mid)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    cout << "Case " << kk << ": ";
    cout << ans << "\n";
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
