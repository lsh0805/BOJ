#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, M, K, a[10001], v, w, visited[10001];
vector<vector<int>> adj;

int dfs(int curr){
    visited[curr] = true;
    int ret = a[curr];
    for(int next : adj[curr]){
        if(visited[next] == false)
            ret = min(ret, dfs(next));
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    adj.resize(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < M; i++){
        cin >> v >> w;
        v--, w--;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int sum = 0;
    for(int i = 0; i < N; i++)
        if(visited[i] == false)
            sum += dfs(i);
    if(sum > K)
        cout << "Oh no";
    else
        cout << sum;
    return 0;
}