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

int N,M;
string a, b;
map<string, string> m;

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        m[a] = b;
    }
    while(M--) {
        cin >> a;
        cout << m[a] << endl;
    }
    return 0;
}