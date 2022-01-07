#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx];

int cur[mx], node[mx][11], tot_nodes=1;

void add_string(string &s1)
{
    int now=1;
    //cout << "Now is: " << now << "\n";
    cur[now]++;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'0';
        if(!node[now][id])
            node[now][id] = ++tot_nodes;
        now = node[now][id];
        cur[now]++;
    }
}

int search_prefix(string s1)
{
   int now=1;
   for(int i=0; s1[i]; i++){
      int id = s1[i]-'0';
      if(!node[now][id])
         return 0;
      now = node[now][id];
   }
   return cur[now];
}

void clr()
{
    for(int i=0; i<=tot_nodes; i++){
        cur[i] = 0;
        for(int j = 0; j<10; j++)
            node[i][j] = 0;
    }
    tot_nodes = 1;
}

void solve(int kk)
{
    clr();
    cin >> n;
    bool ok = 1;
    vector < string > v;
    for(int i=1; i<=n; i++){
        string s1;
        cin >> s1;
        add_string(s1);
        v.push_back(s1);
    }

    for(auto s : v){
        if(search_prefix(s) == 1)
            continue;
        ok = 0;
        break;
    }
    cout << "Case " << kk << ": ";
    ok ? cout << "YES\n" : cout << "NO\n";
}   

int32_t main()
{
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
