#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

int T, N, M, ans, a, b, visited[2001];
vector<vi> adj;

bool dfs(int curr, int cnt){
    if(cnt == 5) return true;
    visited[curr] = true;
    for(int next : adj[curr]){
        if(visited[next]) continue;
        if(dfs(next, cnt + 1))
            return true;
    }
    visited[curr] = false;
    return false;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    adj = vector<vi>(N);
    while(M--){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < N; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i, 1)){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}