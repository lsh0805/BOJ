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

int N, ans;

int main()
{
    IO;
    cin >> N;
    int curr = 1;
    while(N) {
        if (curr <= N) {
            N -= curr;
            curr++;
            ans++;
        } else {
            curr = 1;
        }
    }
    cout << ans;
    return 0;
}