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
typedef pair<int, string> pii;

int T, N;
string s;

int main()
{
    IO;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<pii> v = vector<pii>(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].se >> v[i].fi;
        }
        sort(v.begin(), v.end());
        cout << v.back().se << endl;
    }
    return 0;
}