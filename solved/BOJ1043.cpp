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

int N, M, cnt, num;
vector<int> v[51];
bool know[51], cant[51];

int main()
{
    IO;
    cin >> N >> M >> cnt;
    int ans = M;
    for (int i = 0; i < cnt; i++) {
        cin >> num;
        know[num] = true;
    }
    for (int i = 0; i < M; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> num;
            v[i].push_back(num);
        }
    }
    while(true) {
        bool flag = false;
        for (int i = 0; i < M; i++) {
            if (cant[i]) continue;
            for (int num : v[i]) {
                if (know[num]) {
                    cant[i] = true;
                    ans--;
                    for (int num : v[i]) {
                        if (!know[num]) {
                            know[num] = true;
                            flag = true;
                        }
                    }
                    break;
                }
            }
        }
        if (!flag) break;
    }
    cout << ans << endl;
    return 0;
}