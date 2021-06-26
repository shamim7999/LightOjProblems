#include<bits/stdc++.h>
using namespace std;
#define MAX 7
#define ll long long int
const ll MOD = 10007;
const ll MOD2 = MOD * MOD * 3;

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
            ans.m[i][j] = sm % MOD;
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

void solve(int kk)
{
    int dim;
    Matrix A(6, 1), T(6, 6);
    T.m[1][1] = 1;
    T.m[1][2] = 1;
    T.m[1][3] = 1;
    T.m[1][4] = 1;
    T.m[1][5] = 0;
    T.m[1][6] = 0;

    T.m[2][1] = 0;
    T.m[2][2] = 0;
    T.m[2][3] = 1;
    T.m[2][4] = 1;
    T.m[2][5] = 0;
    T.m[2][6] = 0;

    T.m[3][1] = 0;
    T.m[3][2] = 1;
    T.m[3][3] = 0;
    T.m[3][4] = 1;
    T.m[3][5] = 0;
    T.m[3][6] = 0;

    T.m[4][1] = 1;
    T.m[4][2] = 0;
    T.m[4][3] = 0;
    T.m[4][4] = 0;
    T.m[4][5] = 0;
    T.m[4][6] = 0;

    T.m[5][1] = 0;
    T.m[5][2] = 1;
    T.m[5][3] = 0;
    T.m[5][4] = 0;
    T.m[5][5] = 0;
    T.m[5][6] = 0;

    T.m[6][1] = 0;
    T.m[6][2] = 0;
    T.m[6][3] = 1;
    T.m[6][4] = 0;
    T.m[6][5] = 0;
    T.m[6][6] = 0;


    A.m[1][1] = 1;
    A.m[2][1] = 1;
    A.m[3][1] = 1;
    A.m[4][1] = 1;
    A.m[5][1] = 1;
    A.m[6][1] = 1;

    cin >> dim;
    cout << "Case " << kk << ": ";
    T = Power(T, dim);
    A = Multiply(A, T);
    cout << A.m[2][1] << "\n";

}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
}
