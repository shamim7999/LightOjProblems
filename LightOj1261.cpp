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
#define mx 32
#define mod 1000000007
#define fr first
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

void solve(int kk)
{
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vector < int > v[mx];


    bitset <mx> b1, mark;
    vector <int> v1,v2;
    for(int i=0; i<n; i++){
        for(int j=0,a; j<k; j++){
            scanf("%d", &a), v[i].pb(a);
        }
    }
    int a,p;
    scanf("%d", &p);
    while(p--) scanf("%d", &a), v1.pb(a), b1[a]=1;
    for(int i=1; i<=m; i++) if(b1[i] == 0) v2.pb(-i);

    for(auto it : v1){

        for(int i=0; i<n; i++){

            for(int j=0; j<v[i].size(); j++){
                if(it == v[i][j]){
                    mark[i] = 1;
                }
            }

        }

    }

    for(auto it : v2){

        for(int i=0; i<n; i++){

            for(int j=0; j<v[i].size(); j++){
                if(it == v[i][j]){
                    mark[i] = 1;
                }
            }

        }

    }

    bool ok=1;
    for(int i=0; i<n; i++) if(!mark[i]) ok=0;

    printf("Case %d: ", kk);
    ok ? printf("Yes\n") : printf("No\n");

}

int main()
{
     //freopen("text.txt", "r", stdin);
     //freopen("text2.txt", "w", stdout);
   //fast;
   int kk=0;
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
