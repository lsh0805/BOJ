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

int N, M, T, a[51][51], x, d, k, remain, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
const int MAX = 2e9;

void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool remove(int num, int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = (x + dx[i] + M) % M;
        if (ny < 1 || ny > N || a[ny][nx] != num) continue;
        if (a[y][x] != MAX) {
            a[y][x] = MAX;
            remain--;
        }
        a[ny][nx] = MAX;
        remain--;
        remove(num, ny, nx);
    }
    return a[y][x] == MAX;
}

int sum() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != MAX) ret += a[i][j];
        }
    }
    return ret;
}

void operate() {
    float avg = (float)sum() / (float)remain;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == MAX) continue;
            if (a[i][j] < avg) a[i][j]++;
            else if(a[i][j] > avg) a[i][j]--;
        }
    }
}

void rotate(int idx, int dir, int k) {
    if (dir == 0)
        std::rotate(a[idx], a[idx] + M - k, a[idx] + M);
    else
        std::rotate(a[idx], a[idx] + k, a[idx] + M);
}

void process(int x, int d, int k) {
    for (int i = x; i <= N; i+=x) {
        rotate(i, d, k);
    }
    bool removed = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != MAX) {
                removed |= remove(a[i][j], i, j);
            }
        }
    }
    if (!removed) {
        operate();
    }
    // print();
}


int main()
{
    IO;
    cin >> N >> M >> T;
    remain = N * M;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    while(T--) {
        cin >> x >> d >> k;
        if (remain > 0) process(x, d, k);
    }
    cout << sum() << endl;
    return 0;
}