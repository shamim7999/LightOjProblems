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

template<typename... T> void read(T&... args) { ((cin >> args), ...); }

template<typename... T> void Read(T&... args){ ((getline(cin,args)), ...); }

template<typename... T> void write(T&&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

/// Code Starts From Here.............................................///

int tc=1;

vector <int> calc(string pattern)
{
    int id=0, sz = len(pattern);
    vector <int> lps(sz);
    for(int i=1; i<sz; ){
        if(pattern[id] == pattern[i]){
            lps[i]=id+1;
            ++id, ++i;
        }
        else{
            if(id!=0) id = lps[id-1];
            else lps[i]=id, ++i;
        }
    }
    return lps;
}

int KMP(string s1, string pattern)
{
    int sum=0;
    vector <int> lps = calc(pattern);

    int i=0, j=0;
    /// i---> s1, j ---->pattern
    while(i<len(s1)){
        if(s1[i] == pattern[j]) ++i, ++j;
        else{
            if(j!=0) j = lps[j-1];
            else j = 0, ++i;
        }
        if(j == len(pattern)) ++sum, j=lps[j-1];
    }
    return sum;
}

void solve(int kk)
{
    string s1, pattern;
    read(s1,pattern);
    write("Case ", kk, ": ", KMP(s1,pattern));
    End;
}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   fast;
   int kk=0;
   read(tc);
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
