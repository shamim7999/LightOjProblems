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



void solve(int kk)
{
    char s1[110], s2[110];
    //getchar();
    scanf(" %[^\n]", s1);
    scanf(" %[^\n]", s2);
	
	string ss1="", ss2="";
	
	for(int i=0; s1[i]; i++){
		if(isalpha(s1[i])){
			if(isupper(s1[i])) s1[i]=tolower(s1[i]);
			ss1+=s1[i];
		}
	}
	
	for(int i=0; s2[i]; i++){
		if(isalpha(s2[i])){
			if(isupper(s2[i])) s2[i]=tolower(s2[i]);
			ss2+=s2[i];
		}
	}
	
	sort(ss1.begin(),ss1.end());
	sort(ss2.begin(),ss2.end());
	
	printf("Case %d: ", kk);
    ss1 == ss2 ? printf("Yes\n") : printf("No\n");
}

int main()
{
   //fast;
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
