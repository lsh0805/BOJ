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
int c[2][26], ans;

int main()
{
    IO;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        c[0][a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++) {
        c[1][b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        ans += abs(c[0][i] - c[1][i]);
    }
    cout << ans << endl;
    return 0;
}