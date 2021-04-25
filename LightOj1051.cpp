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

int n, a[mx], ii, dp[55][2][8], vis[55][2][8], dp2[55][3][8], vis2[55][3][8];
string s1;

bool func(int pos, int isVowel, int taken)
{
    if(isVowel && taken>=3)
        return 0;
    if(!isVowel && taken>=5)
        return 0;

    if(pos>=n){
        return 1;
    }

    int &ret = dp[pos][isVowel][taken], &vv = vis[pos][isVowel][taken];
    if(vv == ii)
        return ret;
    vv = ii;

    int a1 = 0, a2 = 0;
    ret = 0;

    if(pos == 0){
        if(s1[pos] == '?'){
            a1 = func(pos+1, 1, 1) | func(pos+1, 0, 1);
        }
        else{
            if(s1[pos] == 'B'){
                a1 = func(pos+1, 0, 1);
            }
            else{
                a1 = func(pos+1, 1, 1);
            }
        }
    }
    else{
        if(s1[pos] == '?'){
            if(isVowel){
                a1 = func(pos+1, 1, taken+1) | func(pos+1, 0, 1);
            }
            else{ // consonant
                a1 = func(pos+1, 0, taken+1) | func(pos+1, 1, 1);
            }
        }
        else{
            if(s1[pos] == 'B'){
                if(isVowel){
                    a1 = func(pos+1, 0, 1);
                }
                else{
                    a1 = func(pos+1, 0, taken+1);
                }
            }
            else{
                if(isVowel){
                    a1 = func(pos+1, 1, taken+1);
                }
                else{
                    a1 = func(pos+1, 1, 1);
                }
            }
        }
    }

    return ret = (ret | a1);

}

bool func2(int pos, int isVowel, int taken)
{
    if(isVowel && taken>=3){
        return 0;
    }
    if(!isVowel && taken>=5){
        return 0;
    }

    if(pos>=n){
        return 1;
    }

    int &ret = dp2[pos][isVowel][taken], &vv = vis2[pos][isVowel][taken];
    if(vv == ii)
        return ret;
    vv = ii;

    int a1 = 1, a2 = 1;
    ret = 1;
    if(pos == 0){
        if(s1[pos] == '?'){
            a1 = func2(pos+1, 1, 1) & func2(pos+1, 0, 1);
        }
        else{
            if(s1[pos] == 'B'){
                a1 = func2(pos+1, 0, 1);
            }
            else{
                a1 = func2(pos+1, 1, 1);
            }
        }
    }
    else{
        if(s1[pos] == '?'){
            if(isVowel){
                a1 = func2(pos+1, 1, taken+1) & func2(pos+1, 0, 1);
            }
            else{ // consonant
                a1 = func2(pos+1, 0, taken+1) & func2(pos+1, 1, 1);
            }
        }
        else{
            if(s1[pos] == 'B'){
                if(isVowel){
                    a1 = func2(pos+1, 0, 1);
                }
                else{
                    a1 = func2(pos+1, 0, taken+1);
                }
            }
            else{
                if(isVowel){
                    a1 = func2(pos+1, 1, taken+1);
                }
                else{
                    a1 = func2(pos+1, 1, 1);
                }
            }
        }
    }

    return ret = (ret & a1);
}

void solve(int kk)
{
    ++ii;
    cin >> s1;
    n = s1.size();
    for(int i=0; s1[i]; i++){
        if(s1[i] == '?'){
            continue;
        }
        if(s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U'){
            s1[i] = 'A';
        }
        else{
            s1[i] = 'B';
        }
    }
    bool cc = func(0, 0, 0), cc2 = func2(0, 0, 0);

    cout << "Case " << kk << ": ";
    if(!cc && !cc2){
        cout << "BAD\n";
        return;
    }

    (!cc2 || !cc) ? cout << "MIXED\n" : cout << "GOOD\n";
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  memset(dp, -1, sizeof dp);
  memset(vis, -1, sizeof vis);
  memset(dp2, -1, sizeof dp2);
  memset(vis2, -1, sizeof vis2);
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
