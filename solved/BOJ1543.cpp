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

string s1, s2;
int pos, ans;

int main()
{
    IO;
    getline(cin, s1);
    getline(cin, s2);
    while (true) {
        pos = s1.find(s2, pos);
        if (pos == -1) break;
        pos += s2.length();
        ans++;
    }
    cout << ans << endl;
    return 0;
}