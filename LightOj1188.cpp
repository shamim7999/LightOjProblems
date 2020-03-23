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
 
int block, a[mx], cnt[mx], ans, res[mx];
 
struct hello
{
    int L, R, idx;
}q[mx];
 
bool cmp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}
 
void clr()
{
    memo(a,0), memo(q,0), memo(res,0), ans=0, memo(cnt,0);
}
 
void solve(int kk)
{
    clr();
 
    int n,qq;
    scanf("%d %d", &n, &qq);
    block = sqrt(n);
    if(block*block != n) block++;
 
    for(int i=0; i<n; i++) scanf("%d", a+i);
 
    for(int i=0,l,r; i<qq; i++) scanf("%d %d", &l, &r), q[i].L = l-1, q[i].R = r-1, q[i].idx = i;
    sort(q,q+qq,cmp);
 
    int currSum=0;
    int currL=0, currR=0;
    for(int i=0; i<qq; i++){
        int left = q[i].L, right = q[i].R;
        while(currL<left){
            cnt[a[currL]]--;
            if(cnt[a[currL]] == 0) ans--;
            currL++;
        }
        while(currL>left){
            cnt[a[currL-1]]++;
            if(cnt[a[currL-1]] == 1) ans++;
            currL--;
        }
        while(currR<=right){
              cnt[a[currR]]++;
              if(cnt[a[currR]] == 1) ans++;
              currR++;
        }
        while(currR>right+1){
             cnt[a[currR-1]]--;
             if(cnt[a[currR-1]] == 0)  ans--;
             currR--;
        }
 
       res[q[i].idx] = ans;
    }
    printf("Case %d:\n", kk);
    for(int i=0; i<qq; i++) printf("%d\n", res[i]);
}
 
int main()
{
    int t, kk=0;
    t=1;
    scanf("%d", &t);
    while(++kk<=t) solve(kk);
    return 0;
}
