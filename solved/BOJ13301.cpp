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

ll w, h, N;

int main()
{
    IO;
    cin >> N;
    w = 1, h = 1;
    for (int i = 1; i < N; i++) {
        if (i % 2) {
            h += w;
        } else {
            w += h;
        }
    }
    cout << 2 * (w + h) << endl;
    return 0;
}