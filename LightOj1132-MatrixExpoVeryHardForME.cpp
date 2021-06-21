#include <bits/stdc++.h>
using namespace std;
#define MAX 55
#define ll unsigned int
ll MOD;

int ii;


inline ll bigMod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD; b>>=1;
    }
    return res;
}

inline ll inv(ll n) {return bigMod(n,MOD-2);}
inline ll Mul(ll a,ll b) {return (a*b)%MOD;}
inline ll Div(ll a,ll b) {return Mul(a,inv(b));}

/* 1 base row columun index */
struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                //m[i][j] = add(m[i][j]);
            }
        }
    }
};

Matrix Multiply(Matrix A,Matrix B){
    Matrix ans(A.row,B.col);

    for(int i=1;i<=A.row;i++){
        for(int j=1;j<=B.col;j++){
            ans.m[i][j]=0;
            ll sm = 0;
            for(int k=1;k<=A.col;k++){      
               
                sm+=(A.m[i][k]*B.m[k][j]);               
                //sm = add(sm);
            }
            ans.m[i][j] = sm;
        }
    }
    return ans;
}

Matrix Power(Matrix mat,long long p){
    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);

    int n = ans.row;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.m[i][j]=0;
            res.m[i][j]=mat.m[i][j];
        }
        ans.m[i][i]=1;
    }

    while(p){
        if(p&1) ans=Multiply(ans,res);
        res=Multiply(res,res);
        p=p/2;
    }
    return ans;
}


void input_matrix(Matrix &aa)
{
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cin >> aa.m[i][j];
    }
    //cout << aa.m[1][1];
}

void output_matrix(Matrix &aa)
{
  //cout << aa.row << " " << aa.col << "\n\n";
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cout <<  aa.m[i][j] << " ";
        cout << "\n";
    }   
}

long long nck[55][55];

void calc_nck(int N, int K)
{
  for(int i=1; i<=N; i++){
    nck[i][0] = nck[i][i] = 1;
    for(int j=1; j<i; j++){
      nck[i][j] = nck[i-1][j-1]+nck[i-1][j];
    }
  }

  nck[0][0]=1;
}

void solve(int kk)
{ 
  long long nth;
  int k;
  cin >> nth >> k;
  Matrix A(k+2, 1), T(k+2, k+2);

  cout << "Case " << kk << ": ";
  if(nth == 1){
    cout << 1 << "\n";
    return;
  }
  A.m[1][1] = T.m[1][1] = 1;
  for(int i=2; i<=k+2; i++){
    A.m[i][1] = 1;
    T.m[1][i] = nck[k][i-2];
  }
  for(int i=2; i<=k+2; i++){
    T.m[2][i] = T.m[1][i];
  }
  
  int sub = 1;
  for(int i=3; i<=k+2; i++){
    for(int j=i, y = 0; j<=k+2; j++, y++){
      T.m[i][j] = nck[k-sub][y];
    }
    ++sub;
  }

  T = Power(T, nth-1);
  A = Multiply(T, A); 
  cout << A.m[1][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    calc_nck(55, 55);
    cin >> t;
    for(int i=1; i<=t; i++)
      solve(i);
}
