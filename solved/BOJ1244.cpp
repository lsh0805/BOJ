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

int N, a[101], M, g, num;

void f_1(int x) {
    int num = x;
    while(x <= N) {
        a[x] = !a[x];
        x += num;
    }
}

void f_2(int x) {
    int st = x, ed = x;
    while(st >= 1 && ed <= N) {
        if (a[st] == a[ed]) {
            a[st] = !a[st];
            if (st != ed)
                a[ed] = !a[ed];
        } else {
            break;
        }
        st--, ed++;
    }
}

int main()
{
    IO;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> g >> num;
        g == 1 ? f_1(num) : f_2(num);
    }
    for (int i = 1; i <= N; i++) {
        cout << a[i];
        if (i % 20 == 0) cout << "\n";
        else cout << " ";
    }
    return 0;
}