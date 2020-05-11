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
unordered_map <ll,bool> mp;
unordered_map <ll,ll> cc;

ll calc(ll mid)
{
    ll sum=0;
    for(ll i=5; i<=mid; i*=5){
        sum+=(mid/i);
    }
    return sum;
}

void solve(int kk)
{
   write("Case ", kk , ": ");
   bool ok=0;
   ll zer,res=0;
   read(zer);
   ll l=0, r=1e18, mid=0;
   while(l<r){
      mid = (l+r)/2;
      res = calc(mid);
      //write(mid, " ---> ", res, "\n");
      if(res == zer){
        ok=1;

        break;
      }
      if(zer<res)  r = mid-1;
      else if(zer>res) l = mid+1;

   }
   if(!ok) write("impossible\n");
   else{
      ll mm = mid%5;
      mid-=mm;
      write(mid,"\n");
   }

}

int main()
{
    //in("text.txt");
    //out("text2.txt");

   //fast;

   //calc();
   int kk=0;
   read(tc);
   //cin >> tc;
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
