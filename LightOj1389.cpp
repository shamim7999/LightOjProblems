#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define nthElement(x) find_by_order(x)
#define lessThan(x) order_of_key(x)
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1000077
#define mod 1000000007
#define fr first
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define trailingZero(x) __builtin_ctz(x)
#define len(ele) (ele).size()

template<typename... T> void get(T&... args) { ((cin >> args), ...); }

template<typename... T> void Get(T&... args){ ((getline(cin,args)), ...); }

template<typename... T> void print(T&&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
ld rad(ld x) {  return ((ld)PI*x)/180.0; }

/// Code Starts From Here.............................................///

int tc=1,n;
string s1;
void solve(int kk)
{
    int dot=0;
    scanf("%d", &n);
    cin >> s1;
    n = len(s1);
    /*
    
    ...
    ..#
    .#.
    Require 1 Scarecrow
    */
    for(int i=0; i<n; i++){
        if(s1[i] == '.'){
            if(i+2<n){
                if(s1[i] == '.' && s1[i+1] == '.' && s1[i+2] == '.')
                    s1[i] = s1[i+1] = s1[i+2] = '#', ++dot;
                else if(s1[i] == '.' && s1[i+1] == '.' && s1[i+2] == '#')
                    s1[i] = s1[i+1] = s1[i+2] = '#', ++dot;
                else if(s1[i] == '.' && s1[i+1] == '#' && s1[i+2] == '.')
                    s1[i] = s1[i+1] = s1[i+2] = '#', ++dot;
            }
        }

    }
     /*
    
    #..
    #.#
    
    Require 1 Scarecrow
    */
    for(int i=0; i<n; i++){
        if(s1[i] == '#'){
            if(i+2<n){
                if(s1[i] == '#' && s1[i+1] == '.' && s1[i+2] == '.')
                    s1[i] = s1[i+1] = s1[i+2] = '#', ++dot;
                else if(s1[i] == '#' && s1[i+1] == '.' && s1[i+2] == '#')
                    s1[i] = s1[i+1] = s1[i+2] = '#', ++dot;
            }
        }
    }
    
    //checking anything remains
    
    for(int i=0; i<n; i++)
        dot+=(s1[i] == '.');
    if(n<=3 && dot>0) /// special test case: ..   ,   .   ,   ...   require 1 scarecrow
        dot=1;
    printf("Case %d: %d\n", kk, dot);


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
