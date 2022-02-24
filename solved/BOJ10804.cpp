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

int N = 20;

int main()
{
    IO;
    vector<int> v = vector<int>(N);
    iota(v.begin(), v.end(), 1);
    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        reverse(v.begin() + a, v.begin() + b);
    }
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    return 0;
}