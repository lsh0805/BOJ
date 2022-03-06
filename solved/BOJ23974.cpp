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

int N, K;
list<pair<pii, pii>> l;

int main()
{
    IO;
    cin >> N >> K;
    l.push_back({{1, 0}, {0, 1}});
    for (int k = 1; k <= K; k++) {
        pair<pii, pii> curr_status;
        int idx = 0;
        for (auto it = l.rbegin(); it != l.rend(); ++it) {
            idx++;
            auto status = *it;
            if (idx % 2) {
                curr_status.first.first |= !status.second.second;
                curr_status.first.second |= !status.second.first;
                curr_status.second.first |= !status.first.first;
                curr_status.second.second |= !status.first.second;
            } else {
                curr_status.first.first |= !status.second.first;
                curr_status.first.second |= !status.second.second;
                curr_status.second.first |= !status.first.first;
                curr_status.second.second |= !status.first.second;
            }
        }
        l.push_back(curr_status);
        if (l.size() > 4) l.pop_front();
    }
    pii result = l.back().first;
    if (N % 2) {
        cout << (result.second ? "YG" : "HS");
    } else {
        cout << (result.first ? "YG" : "HS");
    }
    return 0;
}