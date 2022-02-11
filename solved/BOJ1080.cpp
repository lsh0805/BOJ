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

int N, M, ans;
string a[51], b[51];

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

void f(int y, int x) {
    if (x > M - 3) return f(y + 1, 0);
    if (y > N - 3) return;
    if (a[y][x] != b[y][x]) {
        for (int i = y; i < y + 3; i++) {
            for (int j = x; j < x + 3; j++) {
                a[i][j] = (a[i][j] == '1' ? '0': '1');
            }
        }
        ans++;
    }
    f(y, x + 1);
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    if (N < 3 || M < 3) {
        if (!check()) {
            cout << -1;
            return 0;
        } else {
            cout << 0;
            return 0;
        }
    }
    f(0, 0);
    if (!check()) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}