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
#define mx 260005
#define mod 2600000007
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

int tc=1;

string convert(string &s1)
{
    if(s1.size()<=2) return s1;
    sort(s1.begin()+1, s1.end()-1);
    return s1;
}

void solve(int kk)
{
    unordered_map <string,int> mp;

    int n,cc=1;
    char ch;

    scanf("%d", &n);

    string s1[n+2], help="";

    for(int i=0; i<n; i++){
        cin >> s1[i];
        s1[i] = convert(s1[i]);
        mp[s1[i]]++;
    }

    int m;
    scanf("%d", &m);

    char ss[10000+34];

    getchar();

    printf("Case %d:\n", kk);

    for(int k=1; k<=m; k++){
        ll mul=1, sum=0;

        scanf(" %[^\n]", ss);

        bool suru=0;

        for(int i=0; ss[i]; i++){

            if(isalpha(ss[i])) help+=ss[i], suru=1;

            else{
               if(suru) {
                    help = convert(help);
                    //cout << help << " ";
                    sum=mp[help];
                    mul*=sum;
                    help="", suru=0;
               }
            }
        }
                    ll pum=1;
                    if(help.size()>0){
                        help = convert(help);
                        sum=mp[help];
                        mul*=sum;
                    }

                    help="", suru=0;

                    printf("%lld\n", mul);

    }


}

int main()
{
   int kk=0;
   scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
