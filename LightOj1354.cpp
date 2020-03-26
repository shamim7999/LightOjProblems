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
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc;
string s1,s2;

unordered_map < string, string > mp;

void calc(int num)
{
    bitset <8> b1(num);
    mp[to_string(num)] = b1.to_string();
}

void solve(int kk)
{
    printf("Case %d: ", kk);
    string a1[4], b1[4], helper="";
    int cc=0;
    for(int i=0; i<4; i++) a1[i]="", b1[i]="";
    int len = s1.size();
    for(int i=0; i<len; i++){
        if(s1[i]!='.') helper+=s1[i];
        if(i == len-1){
            a1[cc] = helper;
            helper="",cc=0;
            break;
        }
        if(s1[i] == '.'){
            a1[cc] = helper;
            helper="";
            ++cc;
        }

    }
    len = s2.size();
    for(int i=0; i<len; i++){
        if(s2[i]!='.') helper+=s2[i];
        if(i == len-1){
            b1[cc] = helper;
            helper="",cc=0;
            break;
        }
        if(s2[i] == '.'){
            b1[cc] = helper;
            helper="";
            ++cc;
        }

    }

    for(int i=0; i<4; i++){
        if(mp[a1[i]]!=b1[i]){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");


}

int main()
{

   for(int i=0; i<256; i++) calc(i);
   //fast;
   int kk=0;
   //cin >> t;
   scanf("%d", &tc);
   for(int i=1; i<=tc; i++){
      cin >> s1 >> s2;
      solve(i);
   }


   return 0;
}
