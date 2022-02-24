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
typedef pair<int, int> pii;

int m, f;

int main()
{
    IO;
    while(true) {
        cin >> m >> f;
        if (m == 0 && f == 0) break;
        cout << m + f << endl;
    }
    return 0;
}