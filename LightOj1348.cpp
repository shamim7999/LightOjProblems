#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], lvl[mx], par[mx][24], st[mx], en[mx], Time, tot;
int LogArray[mx];
vector < int > g[mx];
ld LOG(ld e, ld b){ return log(e)/log(b); }

void clr()
{
    Time = 1;
    for(int i=0; i<=n; i++){
        g[i].clear();
    }
}

void dfs(int node, int father, int dep)
{
    st[node] = Time;
    //a[Time] = node;
    lvl[node] = dep;
    par[node][0] = father;

    ++Time;

    for(auto child : g[node]){
        if(child == father)
            continue;
        dfs(child, node, dep+1);
    }

    en[node] = Time;
    //a[Time] = node;
    ++Time;
}

int lca(int u, int v)
{
    if(lvl[u]<lvl[v]) swap(u,v);

    int diff = lvl[u]-lvl[v];

    while(diff>0){
        //int cc = LOG(diff,2);
        int cc = LogArray[diff];
        u = par[u][cc];
        diff -= (1<<cc);
    }
    while(u!=v){
        int cc = LogArray[lvl[u]];
        // for(; cc>0 && par[u][cc] == par[v][cc]; cc--);
        if(cc>0 && par[u][cc] == par[v][cc]) cc=0;
        u = par[u][cc], v = par[v][cc];
    }
    return u;
}

void build()
{
    tot = LogArray[n]+1;
    for(int j=1; j<tot; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1]!=-1) par[i][j] = par[par[i][j-1]][j-1];
            else par[i][j]=-1;
        }
    }
}

namespace Segment_Tree
{
    const int N = 100005;
    int tree[N*4], bb[N];
    int Merge(int x, int y)
    {
        return (x+y);
    }
    void update(int node, int b, int e, int i, int val)
    {
        if(i>e || i<b)return;
        if(b>=i && e<=i){
            tree[node] = val;
            return;
        }
        int mid=(b+e)/2;
        int left=node*2;
        int right=left+1;
        update(left,b,mid,i,val);
        update(right,mid+1,e,i,val);
        tree[node]=Merge(tree[left],tree[right]);
    }

    void init(int node,int be,int en)
    {
        //Lazy[node]=0;
        if(be==en)
        {
            tree[node]=bb[be];
            return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        tree[node]=Merge(tree[node*2],tree[node*2+1]);
    }

    int Query(int node, int b, int e, int i, int j)
    {
        //relax(node,b,e);
        if(i>e || j<b)return 0;
        if(b>=i && e<=j)return tree[node];

        int mid=(b+e)/2;
        int left=node*2;
        int right=left+1;
        int p=Query(left,b,mid,i,j);
        int q=Query(right,mid+1,e,i,j);
        return Merge(p,q);
    }


}

using namespace Segment_Tree;

void calc()
{
    for(int i=1; i<=40000; i++)
        LogArray[i] = log2(i);
}

void solve(int kk)
{
    clr();
    //cin >> n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);

    for(int i=1, x, y; i<n; i++){
        //cin >> x >> y;
        scanf("%d %d", &x, &y);
        ++x, ++y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1, 0);
    build();
    //cout << Time << "\n";
    for(int i=1; i<=n; i++){
        bb[st[i]] = a[i];
        bb[en[i]] = -a[i];
    }

    init(1, 1, 2*n);
    printf("Case %d:\n", kk);
    int q;
    scanf("%d", &q);
    while(q--){
        int x, y;
        //cin >> x;
        scanf("%d", &x);
        
        if(x == 0){
            scanf("%d %d", &x, &y);
            ++x, ++y;
            
            int xx = lca(x, y);
           
            x = st[x], y = st[y], xx = st[xx];
            int a1 = Query(1, 1, 2*n, xx, x);
            int a2 = Query(1, 1, 2*n, xx, y);
            int a3 = Query(1, 1, 2*n, xx, xx);
            printf("%d\n", a1+a2-a3);
        }
        else{
            scanf("%d %d", &x, &y);
            ++x;
            update(1, 1, 2*n, st[x], y);
            update(1, 1, 2*n, en[x], -y);
        }
        //++x, ++y;
    }

}

int main()
{
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  int t=1;
  scanf("%d",&t);
  calc();
  //cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
