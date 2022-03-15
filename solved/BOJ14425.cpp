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

int N, M, ans;
string str;
set<string> s;

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }
    while(M--) {
        cin >> str;
        if(s.find(str) != s.end()) ans++;
    }
    cout << ans;
    return 0;
}