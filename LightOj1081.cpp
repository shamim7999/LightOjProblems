/// Sparse Table needed

#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 250005
#define ll long long
#define mod 1000000007
#define ld long double
#define MAX_logN 20

int a[mx];
int n,m,ii,k;
int ST[mx][MAX_logN];
int Jump_LOG[mx];

void calc()
{
    for(int i=1; i<=mx-3; i++)
      Jump_LOG[i] = log2(i);
}

void Build_Sparse()
{

  for(int i=1;i<=n;i++)ST[i][0]=a[i];

  for(int i=2;i<=n;i++)Jump_LOG[i]=Jump_LOG[i-1]+!(i&(i-1));

  for(int j=1;(1<<j)<=n;j++)
  {
    for(int i=1;(i+(1<<j)-1)<=n;i++)
    {
           ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
    }
  }
}

int query(int i,int j)
{
  int boro_lav=Jump_LOG[j-i+1];
  return max(ST[i][boro_lav],ST[j-(1<<boro_lav)+1][boro_lav]);
}

void solve(int kk)
{
  //clr();
    int r, c, x, q, aa, bb;
    cin >> r >> q;

    for(int i=1; i<=r; i++){
      for(int j=1; j<=r; j++){
        int xx;
        cin >> xx;
        
        int pos = ((i-1)*r+1)+(j-1);
        a[pos] = xx;
      }
    }

    n = r*r;
    
    Build_Sparse();

    cout << "Case " << kk << ":\n";
    while(q--){
      int x, y, s, s1, s2, e1, e2;
      cin >> x >> y >> s;
      s1 = x, e1 = y;
      int mm = -1;
      for(int i=1; i<=s; i++){
        int xx = s1-1;
        int pos = ((s1-1)*r+1)+(e1-1);
        mm = max(mm, query(pos, pos+s-1));
        s1++;
      }
      cout << mm << "\n";
  }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  calc();
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
