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

int w[10], k[10];

int main()
{
    IO;
    for (int i = 0; i < 10; i++)
        cin >> w[i];
    for (int i = 0; i < 10; i++)
        cin >> k[i];
    sort(w, w + 10);
    sort(k, k + 10);
    cout << w[9] + w[8] + w[7] << " " << k[9] + k[8] + k[7];
    return 0;
}