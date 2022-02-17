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

int a, b, c, d;

int main()
{
    IO;
    cin >> a >> b >> c >> d;
    cout << min(a + d, b + c);
    return 0;
}