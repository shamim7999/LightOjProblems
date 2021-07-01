#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 1429431
#define ll long long
#define mod 1000000007
#define ld long double

int tree[mx*3+5], ans[100005];

int Merge(int x, int y)
{
    return x+y;
}

void init(int node, int b, int e)
{
    if(b == e){
        b&1 ? tree[node] = 1 : tree[node] = 0;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=Merge(tree[left],tree[right]);
}

void update(int node, int b, int e, int i, int val)
{
    if(i>e || i<b)return;
    if(b>=i && e<=i){
        tree[node]=val;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=Merge(tree[left],tree[right]);
}

int Query(int node, int b, int e, int cc)
{
    /// Query Funtion Taken from -> https://github.com/AshrafulHaqueToni/Lightoj-solution/blob/master/lightoj%201097.cpp
    if(b == e)
        return b;
    int mid = (b+e)/2;
    int left = 2*node;
    int right = left+1, p;
    if(tree[left]>=cc){
        p = Query(left, b, mid, cc);
    }
    else{
        p = Query(right, mid+1, e, cc-tree[left]);
    }
    return p;
}

void calc()
{   
    int i , j , k;
    
    init(1, 1, mx);

    ans[1] = 1;

    for(int i=2; i<=100000; i++){
        int pos = -1;
        pos = Query(1, 1, mx, i);
        if(pos == -1)
            break;
        ans[i] = pos;
        for(int j=pos; j<=mx; j+=(pos-1)){
            int pos2 = -1;
            pos2 = Query(1, 1, mx, j);
            if(pos2 == -1)
                break;
            update(1, 1, mx, pos2, 0);
        }
    }
}
void solve(int kk)
{
    int id;
    cin >> id;
    cout << "Case " << kk << ": " << ans[id] << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  //scanf("%d",&t);
  calc();
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
