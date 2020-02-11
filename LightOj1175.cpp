#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 210
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

int janeTime[mx][mx], fireTime[mx][mx],r,c,ans=INT_MAX;
char s1[mx][mx];
queue < pair<int,int> > q;

void bfs1(int x, int y)
{
    q.push({x,y});
    fireTime[x][y] = 1;
    while(!q.empty()){
        int a = q.front().fr;
        int b = q.front().se;

        q.pop();

        if(b+1<c && fireTime[a][b]+1<fireTime[a][b+1] && s1[a][b+1] == '.') fireTime[a][b+1] = fireTime[a][b]+1, q.push({a,b+1});
        if(b-1>=0 && fireTime[a][b]+1<fireTime[a][b-1] && s1[a][b-1] == '.') fireTime[a][b-1] = fireTime[a][b]+1, q.push({a,b-1});
        if(a+1<r && fireTime[a][b]+1<fireTime[a+1][b] && s1[a+1][b] == '.') fireTime[a+1][b] = fireTime[a][b]+1, q.push({a+1,b});
        if(a-1>=0 && fireTime[a][b]+1<fireTime[a-1][b] && s1[a-1][b] == '.') fireTime[a-1][b] = fireTime[a][b]+1, q.push({a-1,b});
    }
}

void bfs2(int x, int y)
{
    q.push({x,y});
    janeTime[x][y]=1;
    while(!q.empty()){
        int a = q.front().fr;
        int b = q.front().se;

        q.pop();

        if(a == 0 || b == 0 || a == r-1 || b == c-1){
            ans = min(ans,janeTime[a][b]);
            return;
        }
        if(b+1<c && janeTime[a][b]+1<janeTime[a][b+1] && janeTime[a][b]+1<fireTime[a][b+1] && s1[a][b+1] == '.'){
             janeTime[a][b+1] = janeTime[a][b]+1, q.push({a,b+1});
        }
        if(b-1>=0 && janeTime[a][b]+1<janeTime[a][b-1] && janeTime[a][b]+1<fireTime[a][b-1] && s1[a][b-1] == '.'){
             janeTime[a][b-1] = janeTime[a][b]+1, q.push({a,b-1});
        }
        if(a+1<r && janeTime[a][b]+1<janeTime[a+1][b] && janeTime[a][b]+1<fireTime[a+1][b] && s1[a+1][b] == '.'){
             janeTime[a+1][b] = janeTime[a][b]+1, q.push({a+1,b});
        }
        if(a-1>=0 && janeTime[a][b]+1<janeTime[a-1][b] && janeTime[a][b]+1<fireTime[a-1][b] && s1[a-1][b] == '.'){
             janeTime[a-1][b] = janeTime[a][b]+1, q.push({a-1,b});
        }

    }
}

void solve(int tc)
{

    printf("Case %d: ", tc);
    int x,y,a=INT_MAX,b=INT_MAX;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++){
        scanf("%s", s1[i]);
        for(int j=0; j<c; j++) fireTime[i][j]=10000, janeTime[i][j]=10000;
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(s1[i][j] == 'F'){
                bfs1(i,j);
            }
            if(s1[i][j] == 'J'){
                x=i, y=j;
            }
        }
    }

    bfs2(x,y);
    ans == INT_MAX ? ( printf("IMPOSSIBLE\n") ) : ( printf("%d\n", ans) );
    ans=INT_MAX;
}

int main()
{
    //freopen("text.txt", "r", stdin);
   int t=1,tc=0;
   scanf("%d", &t);
   while(++tc<=t) solve(tc);

   return 0;
}
