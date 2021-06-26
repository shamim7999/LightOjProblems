#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;

//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define mx 100005
#define int long long
#define mod 1000000007
#define ld long double

int n, a[mx];
vector < int > v;
void solve(int kk)
{
    v.clear();
    //cin >> n;
    int oo, ss;
    cin >> oo >> ss;
    oo-=ss;
    for(int ss=1; ss*ss<=oo; ss++){
        if(oo%ss == 0){
            if(ss>ss) v.push_back(ss);
            if(oo/ss>ss) v.push_back(oo/ss);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "Case " << kk << ": ";
    if(v.empty()){
        cout << "impossible\n";
        return;
    }
    int sz = v.size();
    cout << v[0];
    for(int i=1; i<sz; i++){
        cout << " " << v[i];
    }
    cout << "\n";

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
