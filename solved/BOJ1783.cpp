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

int N, M;

int main()
{
    IO;
    cin >> N >> M;
    if (N == 1) {
        cout << "1\n";
    } else if (N == 2) {
        cout << min((M - 1) / 2  + 1, 4) << endl;
    } else {
        if (M - 2 < 4) {
            cout << min(M, 4) << endl;
        } else {
            cout << M - 2 << endl;
        }
    }
    return 0;
}