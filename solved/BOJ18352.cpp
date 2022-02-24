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

int N, M, K, X, a, b, level;
vector<int> adj[300001];
bool visited[300001];
queue<int> q;
int main()
{
    IO;
    cin >> N >> M >> K >> X;
    while(M--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
    q.push(X - 1);
    visited[X-1] = true;
    while(!q.empty() && level < K) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int top = q.front();
            q.pop();
            for (int next : adj[top]) {
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        level++;
    }
    if (level < K || q.empty())
        cout << -1;
    else {
        vector<int> v;
        while(!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << (v[i] + 1) << "\n";
        }
    }
    return 0;
}