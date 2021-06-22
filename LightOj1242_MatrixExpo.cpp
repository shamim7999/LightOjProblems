#include<bits/stdc++.h>
using namespace std;
#define MAX 33
#define ll long long int
const ll MOD = 10;
const ll MOD2 = 1e9+7;

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
                m[i][j] %= MOD;
                if(m[i][j] < 0) m[i][j] += MOD;
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
                if(sm >= MOD2) sm -= MOD2;
            }
            if(sm>=MOD)
                sm%=MOD;
            ans.m[i][j] = sm;
            
        }
    }
    return ans;
}

Matrix Addition(Matrix A, Matrix B)
{
  Matrix ans(A.row, A.col);
  for(int i=1; i<=A.row; i++){
    for(int j=1; j<=A.col; j++){
      ans.m[i][j] = A.m[i][j]+B.m[i][j];
      if(ans.m[i][j]>=MOD)
        ans.m[i][j]-=MOD;
    }
  }
  return ans;
}

Matrix Power(Matrix mat,ll p){
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

Matrix func(Matrix A, int k)
{
  if(k == 1)
    return A;
  Matrix res,tem;
  res = func(A, k/2);
  tem = Addition(res, Multiply(Power(A, k/2), res));
  if(k&1){
    tem = Addition(tem, Power(A, k));
  }
  return tem;
}

void input_matrix(Matrix &aa)
{
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cin >> aa.m[i][j];
    }
}

void output_matrix(Matrix &aa)
{
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cout <<  aa.m[i][j] << "";
        cout << "\n";
    }   
}
void solve(int kk)
{ 
  int k, n;
  cin >> n >> k;
  Matrix A(n, n);
  input_matrix(A);
  
  cout << "Case " << kk << ":\n";
  A = func(A, k);
  output_matrix(A);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //calc_nck(55, 55);
    cin >> t;
    for(int i=1; i<=t; i++)
      solve(i);
}
