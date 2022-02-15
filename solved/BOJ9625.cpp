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

int a[50], b[50], K;

int main()
{
    IO;
    cin >> K;
    a[0] = 1;
    for(int i = 1; i <= K; i++) {
        a[i] = b[i - 1];
        b[i] = a[i - 1] + b[i - 1];
    }
    cout << a[K] << " " << b[K];
    return 0;
}