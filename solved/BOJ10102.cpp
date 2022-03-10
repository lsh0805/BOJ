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

int N, a, b;
char c;
int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c;
        if (c == 'A') {
            a++;
        } else {
            b++;
        }
    }
    if (a > b) cout << "A";
    else if (a < b) cout << "B";
    else cout << "Tie";
    return 0;
}