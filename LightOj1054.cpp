#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long

const ll mod = 1e9+7;

vector <ll> v;
map <ll, ll> cnt;


ll bigmod(ll e, ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}
ll ModInverse(ll x){return bigmod(x,mod-2)%mod;}

void func(ll n)
{
    v.clear();
    cnt.clear();
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0){
            cnt[i]=0;
            v.push_back(i);
            while(n%i == 0){
                //v.push_back(i);
                n/=i;
                cnt[i]++;
            }
        }
    }

    if(n>=2){
        cnt[n]=0;
        cnt[n]++;
        v.push_back(n);
    }

}

void dec(ll &x)
{
    if(x>=mod)
        x%=mod;
    if(x<0)
        x+=mod;
}

void solve(int kk)
{


    //cout << Pow(1000000007, 5) << "\n";

    ll n, m, sum=1;
    cin >> n >> m;
    func(n);

    for(auto it : v){
        ll a = 1, r = it, po = (cnt[it]*m)+1;

        //ll yo = (a*(powl(r, po)-1))/(r-1);

        //cout << po << "\n\n";

        ll lob, hor, yo;

        lob = bigmod(r, po)-1;

        dec(lob);

        lob = a*lob;
        dec(lob);

        hor = ModInverse(r-1);
        dec(hor);

        yo = lob*hor;
        dec(yo);

        sum*=yo;
        dec(sum);

    }
    

    cout << "Case " << kk << ": " << sum << "\n";


}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   //fast;
   int t=1,kk=0;
   //calc();
   //scanf("%d", &t);
   cin >> t;
   while(++kk<=t) solve(kk);

   return 0;
}
