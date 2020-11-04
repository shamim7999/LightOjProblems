#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n, k;
vector <int> v;
 
void calc()
{
    for(int i=0; i<26; i++)
        v.push_back(i);
}
 
void solve(int tc)
{
    sort(v.begin(), v.end());
    int n, k;
    scanf("%d %d", &n, &k);
    printf("Case %d:\n", tc);
    do{
        for(int i=0; i<n; i++){
            printf("%c", v[i]+'A');
        }
        printf("\n");
        --k;
    }
    while(next_permutation(v.begin(), v.begin()+n) && k>0);
 
}
 
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    calc();
    int t;
    //cin >> t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
        solve(i);
   
}
