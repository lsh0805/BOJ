#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

double D, H, W;

int main()
{
    IO;
    cin >> D >> H >> W;
    double x = sqrt((D * D) / (H * H + W * W));
    int a = x * H;
    int b = x * W;
    cout << a << " " << b;
    return 0;
}