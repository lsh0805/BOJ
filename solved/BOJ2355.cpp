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

ll A, B;

int main()
{
    IO;
    cin >> A >> B;
    if (A > B) swap(A, B);
    cout << (B * (B + 1)) / 2 - ((A - 1) * A) / 2;
    return 0;
}