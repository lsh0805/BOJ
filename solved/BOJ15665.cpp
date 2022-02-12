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

int N, M, a[10];
vector<int> v;

void f(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        a[idx] = v[i];
        f(idx + 1);
    }
}

int main()
{
    IO;
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        a[0] = v[i];
        f(1);
    }
    return 0;
}