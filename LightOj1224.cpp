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

struct node
{
    bool endmark;
    node *next[5];
    int cnt;
    node()
    {
        endmark=0,cnt=0;
        for(int i=0; i<4; i++) next[i]=NULL;
    }
} *root;

void Insert(string s1)
{
    node *curr = root;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'A';
        if(curr->next[id] == NULL){
            curr->next[id] = new node();
        }
        curr->cnt++;
        curr = curr->next[id];
    }
    curr->cnt++;
    curr->endmark=1;
}

void delAll(node *curr)
{
    for(int i=0; i<4; i++){
        if(curr->next[i]) delAll(curr->next[i]);
    }
    delete(curr);
    //return 1;
}

int search_prefix(string s1)
{
    node *curr = root;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'A';
        if(curr->next[id] == NULL) return 0;
        curr = curr->next[id];
    }
    return curr->cnt;
}

string convert(string &s1)
{
    for(int i=0; s1[i]; i++){
        if(s1[i] == 'G') s1[i]='B';
        else if(s1[i] == 'T') s1[i]='D';
    }
    return s1;
}

void solve(int kk)
{
    root = new node();
    int n;
    cin >> n;
    string s1[n+2];
    for(int i=0; i<n; i++) cin >> s1[i], Insert(convert(s1[i]));

    string ss, hold="";

    int Max = -1;

    for(int i=0; i<n; i++){
        ss = s1[i];
        hold="";
        for(int j=0; ss[j]; j++){
            hold+=ss[j];
            Max = max(Max, search_prefix(hold)*(j+1));
        }

    }

    printf("Case %d: %d\n", kk, Max);

    delAll(root);
}

int main()
{
   int kk=0;
   cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}
