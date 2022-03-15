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

int M, D;

int main()
{
    IO;
    cin >> M >> D;
    if (M == 2 && D == 18) {
        cout << "Special";
    } else if (M < 2 || (M == 2 && D < 18)) {
        cout << "Before";
    } else {
        cout << "After";
    }
    return 0;
}