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
#define mx 200005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(int n, int pos){ return (n&(1<<pos)); }
bool Set(int n, int pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int a[mx],tree[4*mx], n;
unordered_set < int > s;

void clr()
{
    s.clear();
    memset(tree, -1, sizeof tree);
}

void updateRange(int node, int b, int e, int i, int j, int val)
{
    //if(lazy[node]!=0)relax(node,b,e);
    if(i>e || j<b)return;
    if(b>=i && e<=j){
        tree[node]=val;
        //relax(node,b,e);
        return;
    }
    if(tree[node]>-1){
        tree[node*2] = tree[node*2+1] = tree[node];
        tree[node] = -1;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    updateRange(left,b,mid,i,j,val);
    updateRange(right,mid+1,e,i,j,val);
    //tree[node]=Merge(tree[left],tree[right]);
}


void Query(int node, int b, int e)
{

    if(b == e){
        if(tree[node] != -1)
            s.insert(tree[node]);
        return;
    }
    if(tree[node]>-1){
        tree[node*2] = tree[node*2+1] = tree[node];
        tree[node] = -1;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    Query(left,b,mid);
    Query(right,mid+1,e);
    //return Merge(p,q);
}

//void clr() { memo(tree, 0), memo(lazy, 0), memo(a, 0); }

void solve(int kk)
{
    clr();
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        updateRange(1, 1, 2*n, x, y, i);
    }
    Query(1, 1, 2*n);
    cout << "Case " << kk << ": " << s.size() << "\n";


}

int main()
{
   fast;
   int t=1,kk=0;
   cin >> t;
   //scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
