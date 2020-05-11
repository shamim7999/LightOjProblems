#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 8005
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
#define len(ele) (ele).size()

template <typename T>
void in(T& args)
{
    ((freopen(args, "r", stdin)));
}

template <typename T>
void out(T& args)
{
    ((freopen(args, "w", stdout)));
}

template<typename... T>
void read(T&... args)
{
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args)
{
    ((cout << args << ""), ...);
}

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

/// Code Starts From Here.............................................///

int tc=1;

vector <int> v;

void solve(int kk)
{
   int n,a;
   ll sum=0;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a), v.eb(a);

   sort(all(v));

   for(int i=2; i<n; i++){
       int p1=0, p2=i, ho=0;
       //write(v[i], " -----> ");
       while((p2-p1+1)>=3){
           int lagbe = v[p2]-v[p1]+1;
           auto xx = lower_bound(v.begin()+p1, v.end(), lagbe)-v.begin();

           if(xx == n || v[xx] == v[p2]){
               ++p1;
               con;
           }
           if(v[xx] == v[p1]) ++xx;
           //write(p2-xx, " ");
           sum+=(p2-xx);
           ++p1;
       }
       //End;
   }
   printf("Case %d: %lld\n", kk, sum);
   v.clear();


}

int main()
{
    //in("text.txt");
    //out("text2.txt");

   //fast;

   //calc();
   int kk=0;
   //read(tc);
   //cin >> tc;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
