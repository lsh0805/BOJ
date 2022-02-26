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

int T, C;

int main()
{
    IO;
    cin >> T;
    while(T--) {
        cin >> C;
        cout << C / 25 << " ";
        C %= 25;
        cout << C / 10 << " ";
        C %= 10;
        cout << C / 5 << " ";
        C %= 5;
        cout << C << endl;
    }

    return 0;
}