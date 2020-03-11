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

vector < pair<ll,ll> > v;
ll tree[4*mx], cnt, x;

ll Merge(ll a1, ll a2) { return (a1%mod+a2%mod)%mod; }

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i>e || i<b || b>e)return;
    if(b>=i && e<=i){
        tree[node]=Merge(tree[node],val);
        return;
    }
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=Merge(tree[left],tree[right]);
}

ll Query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b || b>e)return 0;
    if(b>=i && e<=j)return tree[node]%mod;

    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    ll p=Query(left,b,mid,i,j);
    ll q=Query(right,mid+1,e,i,j);
    return Merge(p,q);
}

void clr() { memo(tree, 0), v.clear(), cnt=0; }

bool cmp(pair <ll,ll> &p1, pair <ll,ll> &p2)
{
    if(p1.fr<p2.fr) return 1;
    if(p1.fr == p2.fr) return (p1.se>p2.se);
    return 0;
}

void solve(int tc)
{
    clr();

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &x), v.pb({x,i});
    sort(v.begin(),v.end(), cmp);
    ll sum=0;
    update(1,0,n,0,1);
    for(auto it : v){
        cnt = Query(1,0,n,0,it.se-1);
        update(1,0,n,it.se,cnt);
        sum = (sum%mod+cnt%mod)%mod;
    }
    printf("Case %d: %lld\n", tc, sum);

}

int main()
{
   //fast;
   //freopen("text.txt", "r", stdin);
   int t=1, kk=0;
   scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
