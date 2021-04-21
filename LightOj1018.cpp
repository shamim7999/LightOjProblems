#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 17
#define ll long long
#define mod 1000000007
#define ld long double

struct hello
{
	int x, y;
	hello(){}
	hello(int x, int y)
	{
		this->x = x, this->y = y;
	}
}a[mx];

int n, dp[(1<<mx)+mx], vis[(1<<mx)+mx], ii;

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
 

int __area(hello aa, hello bb, hello cc)
{
	int A, B, C, D;
	A = (aa.x - bb.x), B = (aa.x - cc.x), C = (aa.y - bb.y), D = (aa.y - cc.y);
	int Area = abs(A*D - B*C);
	Area = (Area/2)+(Area%2 == 1);
	return Area; 
}

int func(int mask)
{
	if(mask == (1<<n)-1)
		return 0;
	int &ret = dp[mask], &vv = vis[mask];
	if(vv == ii)
		return ret;
	vv = ii;

	int cnt = n-(__builtin_popcount(mask)); /// how many zeroes?

	int a1 = cnt;
	for(int i=0; i<n; i++){
		if(!chk(mask, i)){
			for(int j=0; j<n; j++){
				if(i!=j && !chk(mask, j)){
					int tem = mask;
					for(int k=0; k<n; k++){
						if(__area(a[i], a[j], a[k]) == 0){
							tem = Set(tem, k);
						}
					}
					a1 = min(a1, 1+func(tem));
				}
			}
			break;
		}
	}
	return ret = a1;
}

void solve(int kk)
{
	++ii;
    cin >> n;
    for(int i=0, xx, yy; i<n; i++){
    	cin >> xx >> yy;
    	a[i] = {xx, yy};
    }
    cout << "Case " << kk << ": " << func(0) << "\n";

}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  memset(dp, -1, sizeof dp);
  memset(vis, -1, sizeof vis);
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
