#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 13
#define ll long long
#define mod 1000000007
#define ld long double

int n, dis[102][mx][mx], r, c, horse;
char s1[mx][mx];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1}; // Knight Direction
bool vis[102][mx][mx];

struct hello
{
	int a, b, c;
	hello(){}
	hello(int a, int b, int c){
		this->a = a, this->b = b, this->c = c;
	}
};

void clr()
{
	memset(dis, -1, sizeof dis);
	memset(vis, 0, sizeof vis);
	horse = 0;
}

int ff(int x, int b) // ceiling value
{
	int xx = (x/b)+(x%b!=0);
	return xx;
}

bool ok(int x, int y)
{
	return (x>=1 && x<=r && y>=1 && y<=c && !vis[horse][x][y]);
}

void bfs(int aa, int bb, int cc)
{
	queue < hello > q;
	q.push({aa, bb, 0});
	//memset(vis, 0, sizeof vis);
	//int step = 0;
	dis[horse][aa][bb] = 0;
	while(!q.empty()){
		int x = q.front().a, y = q.front().b, step = q.front().c;
		q.pop();
		for(int i=0; i<8; i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(ok(xx, yy)){
				vis[horse][xx][yy] = 1;
				dis[horse][xx][yy] = ff(step+1, cc);
				q.push({xx, yy, step+1});
			}
		}
		vis[horse][x][y] = 1;
	}

}

void solve(int kk)
{
	clr();
    cin >> r >> c;
    for(int i=1; i<=r; i++){
    	for(int j=1; j<=c; j++){
    		cin >> s1[i][j];
    	}
    }
    for(int i=1; i<=r; i++){
    	for(int j=1; j<=c; j++){
    		if(s1[i][j]!='.'){
    			int cc = s1[i][j]-'0';
    			++horse;
    			bfs(i, j, cc);
    		}
    	}
    }
    int mm = 1e9;
    for(int i=1; i<=r; i++){
    	for(int j=1; j<=c; j++){
    		int sum = 0;
    		for(int k=1; k<=horse; k++){
    			sum+=(dis[k][i][j]);
    			if(vis[k][i][j] == 0){
    				sum = 1e9;
    				break;
    			}
    		}
    		mm = min(mm, sum);
    	}
    }
    if(mm == 1e9)
    	mm = -1;
    cout << "Case " << kk <<": " << mm << "\n";
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
