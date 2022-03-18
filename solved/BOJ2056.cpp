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

int N, t[10001], indeg[10001], cnt, num, ans, max_;
vector<int> edge[10001];
list<pii> li;

int main()
{
    IO;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> num;
            edge[i].push_back(num);
            indeg[num]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            li.push_back({i, t[i]});
        }
    }
    while(!li.empty()) {
        queue<pii> ready;
        for (auto it = li.begin(); it != li.end();) {
            if (--(*it).se == 0) {
                for (int next : edge[(*it).fi]) {
                    if (--indeg[next] == 0) {
                        ready.push({next, t[next]});
                    }
                }
                it = li.erase(it);
            } else {
                it++;
            }
        }
        while(!ready.empty()) {
            li.push_back(ready.front());
            ready.pop();
        }
        ans++;
    }
    cout << ans;
    return 0;
}