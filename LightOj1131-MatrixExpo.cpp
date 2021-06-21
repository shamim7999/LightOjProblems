#include<bits/stdc++.h>
using namespace std;
#define MAX 7
#define ll long long int
ll MOD;
ll MOD2;
//const ll MOD2 = MOD * MOD * 3;
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
                if(sm >= MOD2) sm %= MOD2;
            }
            ans.m[i][j] = sm;
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

ll Det(Matrix mat){
    assert(mat.row == mat.col);
    int n = mat.row;
    mat.normalize();

    ll ret = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            while(mat.m[j][i]){
                ll t = Div(mat.m[i][i], mat.m[j][i]);
                for(int k = i; k <= n; ++k){
                    mat.m[i][k] -= Mul(mat.m[j][k] , t);
                    if(mat.m[i][k] < 0) mat.m[i][k] += MOD;
                    swap(mat.m[j][k], mat.m[i][k]);
                }
                ret = MOD - ret;
            }
        }

        if(mat.m[i][i] == 0) return 0;
        ret = Mul(ret, mat.m[i][i]);
    }

    if(ret < 0) ret += MOD;
    return ret;
}

ll Tmp[MAX<<1][MAX<<1];
Matrix Inverse(Matrix mat){
    assert(mat.row == mat.col);
    assert(Det(mat) != 0);

    int n = mat.row;
    mat.normalize();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) Tmp[i][j] = mat.m[i][j];
        for(int j=n+1; j<=2*n; j++) Tmp[i][j] = 0;
        Tmp[i][i+n] = 1;
    }

    for(int i=1; i<=n; i++){
        assert(Tmp[i][i] != 0);

        for(int j=1; j<=n; j++){
            if(i == j) continue;
            ll c = Div(Tmp[j][i], Tmp[i][i]);
            for(int k=i; k<=2*n; k++){
                Tmp[j][k] = Tmp[j][k] - Mul(Tmp[i][k], c);
                if(Tmp[j][k] < 0) Tmp[j][k] += MOD;
            }
        }
    }

    Matrix Inv(n,n);
    for(int i=1; i<=n; i++){
        for(int j = 1; j <= n; j++){
            Inv.m[i][j] = Div(Tmp[i][j+n], Tmp[i][i]);
        }
    }
    return Inv;
}

//Freivalds algorithm : check whether AB = C
//Complexity : O(iteration * n^2)
int p[MAX],q[MAX],r[MAX];
bool Freivalds(Matrix A,Matrix B,Matrix C){
    srand(time(NULL));
    int n=A.row;
    int iteration=15;

    int Yes=0;
    for(int i=1;i<=iteration;i++){
        for(int i=1;i<=n;i++) r[i] = rand()%2;
        for(int i=1;i<=n;i++) p[i] = q[i] = 0;

        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                p[i] += r[j] * A.m[i][j];
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                q[i] += p[j] * B.m[i][j];
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                q[i] -= r[j] * C.m[i][j];

        bool All = true;
        for(int i=1;i<=n;i++) if(q[i]) All=false;
        if(All) Yes++;
    }
    return Yes == iteration;
}

void input_matrix(Matrix &aa)
{
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cin >> aa.m[i][j];
    }
    //cout << aa.m[1][1];
}

void output_matrix(Matrix aa)
{
    for(int i=1; i<=aa.row; i++){
        for(int j=1; j<=aa.col; j++)
            cout <<  aa.m[i][j] << " ";
        cout << "\n";
    }   
}

void solve()
{
    
  ll f[3], g[3], a1, b1, c1, a2, b2, c2, M, q, nth;

  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  
  for(int i=1; i<=3; i++)
    cin >> f[i-1];
  for(int i=1; i<=3; i++)
    cin >> g[i-1];
  
  cin >> M >> q;

  MOD2 = M;
  //MOD2 = MOD * MOD * 3;

    Matrix T(6, 6), a(6, 1), ans(6, 1);
    //cout << T.m[1][1];
    

    T.m[1][1] = a1;
    T.m[1][2] = b1;
    T.m[1][3] = 0;
    T.m[1][4] = 0;
    T.m[1][5] = 0;
    T.m[1][6] = c1;

    T.m[2][1] = 1;
    T.m[2][2] = 0;
    T.m[2][3] = 0;
    T.m[2][4] = 0;
    T.m[2][5] = 0;
    T.m[2][6] = 0;
    
    T.m[3][1] = 0;
    T.m[3][2] = 1;
    T.m[3][3] = 0;
    T.m[3][4] = 0;
    T.m[3][5] = 0;
    T.m[3][6] = 0;
    
    T.m[4][1] = 0;
    T.m[4][2] = 0;
    T.m[4][3] = c2;
    T.m[4][4] = a2;
    T.m[4][5] = b2;
    T.m[4][6] = 0;
    
    T.m[5][1] = 0;
    T.m[5][2] = 0;
    T.m[5][3] = 0;
    T.m[5][4] = 1;
    T.m[5][5] = 0;
    T.m[5][6] = 0;
    
    T.m[6][1] = 0;
    T.m[6][2] = 0;
    T.m[6][3] = 0;
    T.m[6][4] = 0;
    T.m[6][5] = 1;
    T.m[6][6] = 0;
 
    a.m[1][1] = f[2];
    a.m[2][1] = f[1];
    a.m[3][1] = f[0];
    a.m[4][1] = g[2];
    a.m[5][1] = g[1];
    a.m[6][1] = g[0];
    cout << "Case " << ++ii << ":\n";

    Matrix tem;

    while(q--){
        cin >> nth;
        if(nth<=2){
            cout << f[nth]%MOD2 << " " << g[nth]%MOD2 << "\n";
            continue;
        }
        tem = Power(T, nth-2);
        //tem.normalize();
        ans = Multiply(tem, a);
        //ans.normalize();
        cout << ans.m[1][1] << " " << ans.m[4][1] << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
