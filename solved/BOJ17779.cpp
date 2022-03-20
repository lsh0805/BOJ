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

int N, a[21][21], total, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
bool border[21][21];

void setBorder(int x, int y, int d1, int d2) {
    memset(border, false, sizeof(border));
    for(int i = 0; i <= d1; i++) {
        int nx = x + i, ny = y - i;
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        border[nx][ny] = true;
    }

    for(int i = 0; i <= d2; i++) {
        int nx = x + i, ny = y + i;
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        border[nx][ny] = true;
    }

    for(int i = 0; i <= d2; i++) {
        int nx = x + d1 + i, ny = y - d1 + i;
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        border[nx][ny] = true;
    }

    for(int i = 0; i <= d1; i++) {
        int nx = x + d2 + i, ny = y + d2 - i;
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        border[nx][ny] = true;
    }
}

int count1(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if(border[i][j]) break;
            ret += a[i][j];
        }
    }
    return ret;
}

int count2(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y2; j >= y1; j--) {
            if(border[i][j]) break;
            ret += a[i][j];
        }
    }
    return ret;
}

int count3(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for (int i = x2; i >= x1; i--) {
        for (int j = y1; j <= y2; j++) {
            if(border[i][j]) break;
            ret += a[i][j];
        }
    }
    return ret;
}

int count4(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for (int i = x2; i >= x1; i--) {
        for (int j = y2; j >= y1; j--) {
            if(border[i][j]) break;
            ret += a[i][j];
        }
    }
    return ret;
}

void printFifthArea() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << border[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int simulate(int x, int y, int d1, int d2) {
    int max_ = 0, min_ = 2e9, sum = 0;
    setBorder(x, y, d1, d2);
    int people[4] = { count1(1, x + d1 - 1, 1, y),
        count2(1, x + d2, y + 1, N),
        count3(x + d1, N, 1, y - d1 + d2 -1),
        count4(x + d2 + 1, N, y - d1 + d2, N)
    };
    for (int i = 0; i < 4; i++) {
        max_ = max(max_, people[i]);
        min_ = min(min_, people[i]);
        sum += people[i];
    }
    max_ = max(max_, total - sum);
    min_ = min(min_, total - sum);
    return max_ - min_;
}

int solve() {
    int ret = 2e9;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (x > N || y > N || x + d1 + d2 > N ||
                        y - d1 < 1 || y - d1 >= y || y + d2 <= y || y + d2 > N)
                        continue;
                    ret = min(ret, simulate(x, y, d1, d2));
                }
            }
        }
    }
    return ret;
}

int main()
{
    IO;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            total += a[i][j];
        }
    }
    cout << solve();
    return 0;
}