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

int n;
double dp[mx];

const int N = 100005;
int lp[N+1];
vector<int> pr;

void Linear_Sieve()
{
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

}

int func(int x)
{
    int X = x;
    if(lp[x] == x)
        return 2;
    int pre = lp[x], mul = 1, sum = 0, xx = lp[x];
    while(x>1){
        xx = lp[x];
        x/=xx;
        ++sum;
        
        if(pre!=xx){
           
            pre = xx;
            mul*=(sum);
            sum = 1;
        }
    }
    pre = xx;
    mul*=(sum+1);
   
    return mul;
}

void calc()
{
    dp[1] = 0;
    for(int i=2; i<=mx-3; i++){
        double sum = 0;
        for(int j=1; j*j<=i; j++){
            if(i%j == 0){
                sum+=(dp[i/j]+1);
                if((i/j)!=j){
                    sum+=(dp[j]+1);
                }
            }
        }
        
        dp[i] = sum/(double)(func(i)-1);
    }
}

void solve(int kk)
{
    cin >> n;
    cout << "Case " << kk << ": ";
    cout << setprecision(10) << dp[n] << "\n";
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  Linear_Sieve();
  calc();
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
