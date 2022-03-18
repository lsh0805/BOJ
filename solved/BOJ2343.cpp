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

int N, M, a[100001];

bool test(int t) {
    int m = 1, sum = 0;
    for (int i = 0; i < N;) {
        if (sum + a[i] > t) {
            m++;
            sum = 0;
        } else {
            sum += a[i];
            i++;
        }
        if (m > M) return false;
    }
    return true;
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9 + 1;
    while(l + 2 < r) {
        int mid = (l + r) / 2;
        if(test(mid)) {
            r = mid + 1;
        } else {
            l = mid + 1;
        }
    }
    if (test(l)) {
        cout << l;
    } else {
        cout << l + 1;
    }
    return 0;
}