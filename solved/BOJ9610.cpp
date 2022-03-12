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

int N, x, y, cnt[6];

int main()
{
    IO;
    cin >> N;
    while(N--){
        cin >> x >> y;
        if (x == 0 || y == 0) {
            cnt[5]++;
        } else if (x > 0 && y > 0) {
            cnt[1]++;
        } else if (x < 0 && y > 0) {
            cnt[2]++;
        } else if (x < 0 && y < 0) {
            cnt[3]++;
        } else if (x > 0 && y < 0) {
            cnt[4]++;
        }
    }
    for (int i = 1; i <= 4; i++) {
        cout << "Q" << i << ": " << cnt[i] << endl;
    }
    cout << "AXIS: " << cnt[5];
    return 0;
}