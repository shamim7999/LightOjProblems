#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

int n, m, k;

void solve(int tc)
{
    double a, b, c, d, x, h, area;
    cin >> a >> b >> c >> d;
    x = (d*d-b*b+a*a-2*a*c+c*c)/(2*a-2*c);
    h = sqrt(d*d-x*x);
    area = .5*h*(a+c);
    cout << setprecision(10) << "Case " << tc << ": " << area << "\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    for(int i=1; i<=t; i++)
        solve(i);
    return 0;

}
