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

int N, M, ans;
string str;

int main()
{
    IO;
    cin >> N >> M >> str;
    int curr = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'I') {
            if (curr % 2) {
                curr = 1;
            } else {
                curr += 1;
            }
        } else {
            if (curr % 2 == 0) {
                curr = 0;
            } else {
                curr += 1;
            }
        }
        if (curr == N * 2 + 1) {
            curr -= 2;
            ans++;
        }
    }
    cout << ans;
    return 0;
}