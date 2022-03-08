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

string a, b;
ll ans;

int main()
{
    IO;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            ans += (a[i] - '0') * (b[j] - '0');
        }
    }
    cout << ans;
    return 0;
}