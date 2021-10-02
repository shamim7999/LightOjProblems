//took Help from Neaj_Morshad_Ashik

#include<bits/stdc++.h>
using namespace std;
#define dd double
//#define int long long
#define ull unsigned long long
#define ld long double
#define mx 800
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, x[mx+5], y[mx+5];

void solve(int kk)
{
   cin >> n;
   for(int i=1; i<=n; i++)
      cin >> x[i] >> y[i];
   int ans = 0;
   cout << "Case " << kk << ": ";
   if(n<=2){
      cout << n << "\n";
      return;
   }

   for(int i=1; i<=n; i++){
      unordered_map < int, int > mp;
      for(int j=1; j<=n; j++){
         if(i == j)
            continue;
         int yy = y[i]-y[j];
         int xx = x[i]-x[j];

         if(xx == 0){
            mp[INT_MAX]++;
            ans = max(ans, mp[INT_MAX]);
            continue;
         }
         int gc = __gcd(xx, yy);
         xx/=gc, yy/=gc;
         int hash_val = 100000*xx+yy;
         mp[hash_val]++;
         ans = max(ans, mp[hash_val]);
      }
   }
   cout << ans+1 << "\n";
}

int main()
{
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
