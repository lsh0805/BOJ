#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int V, E, a, b, c, p[10001], r[10001], ans;
vector<P2> adj;

int find(int u){
    if(p[u] == u) return u;
    return p[u] = find(p[u]);
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if(r[u] < r[v])
        swap(u, v);
    if(u == v) return false;
    p[v] = u;
    if(r[u] == r[v])
        r[u]++;
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    adj = vector<P2>(V);
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        a--, b--;
        adj.push_back(P2(c, P(a, b)));
    }
    for(int i = 0; i < V; i++)
        p[i] = i;
    sort(adj.begin(), adj.end());
    for(int i = 0; i < adj.size(); i++){
        int cost = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if(merge(u, v))
            ans += cost;
    }
    cout << ans;
}