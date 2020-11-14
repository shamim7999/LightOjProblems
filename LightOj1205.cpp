#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[18][2][2][18][2];
ll digit[20];
int len;

void clr()
{
    memset(dp, -1, sizeof dp);
}

ll func(int pos, bool isSmall, bool start, int backPos, bool boro)
{
    if(pos>backPos){
        return (isSmall || !boro);
    }
    ll &ret = dp[pos][isSmall][start][backPos][boro];

    if(ret != -1)
        return ret;
    
    ll a1=0;

    int en = digit[pos];
    if(isSmall)
        en=9;
    for(int i=0; i<=en; i++){
        if(start == 0 && i == 0){
            a1+=func(pos+1, isSmall | (i<en), start | (i>0), backPos, boro);
        }
        else if((i == digit[backPos]) || (pos == backPos) ) {
            a1+=func(pos+1, isSmall | (i<en), start | (i>0), backPos-1, boro);
        }
        else{
             a1+=func(pos+1, isSmall | (i<en), start | (i>0), backPos-1, i > digit[backPos]);
        }
    }

    return ret = a1;
}

ll Go(ll n)
{   
    clr();
    
    len=0;
    stack <ll> s;
    string s1 = to_string(n);
    if(n == 0)
        s.push(n);
    while(n){
        s.push(n%10);
        n/=10;
    }

    while(!s.empty()){
        digit[len] = s.top();
        ++len;
        s.pop();
    }

    return func(0, 0, 0, len-1, 0);
}

void solve(int tc)
{
    ll a, b, extraa=0;
    cin >> a >> b;
    if(a>b)
        swap(a, b);
    extraa = (a == 0);

    if(a>0)
        --a;
  
    cout << "Case " << tc << ": " << Go(b)-Go(a)+extraa << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
    return 0;
}
