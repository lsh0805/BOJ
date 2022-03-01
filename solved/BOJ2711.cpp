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

int T, N;
string s;

int main()
{
    IO;
    cin >> T;
    while(T--) {
        cin >> N >> s;
        s.erase(s.begin() + (N - 1));
        cout << s << endl;
    }
    return 0;
}