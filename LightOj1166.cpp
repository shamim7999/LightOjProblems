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

int n, a[mx];

vector < int > v;

int func(int x)
{
    for(int i=1; i<=n; i++){
        if(v[i] == x)
            return i;
    }
    return -1;
}

void solve(int kk)
{
    cin >> n;
    v.push_back(0);
    for(int i=0, x; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    int xx = 1, st = 0, id = 1;
    while(is_sorted(v.begin(), v.end()) == 0){
        
        int pos = func(xx);
        if(pos != id){
            swap(v[id], v[pos]);
            ++st;
        }
        ++xx, ++id;
    }
    cout << "Case " << kk << ": " << st << "\n";
    v.clear();

}
 
int main()
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
