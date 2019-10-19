#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 19;
int N, M, a, b, c, Q, p[200001], r[200001], parent[200001][MAX], depth[200001], sz[200001], min_value[200001];
typedef pair<int, pair<int, int>> P2;
typedef pair<int, int> P;
vector<int> adj[200001];
priority_queue<P2> edge;

int find(int u){
    if(p[u] == u) return u;
    return p[u] = find(p[u]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    p[v] = u;
}
void dfs(int curr, int d){
    depth[curr] = d;
    for(int next : adj[curr]){
        if(depth[next] > 0) continue;
        parent[next][0] = curr;
        dfs(next, d + 1);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        edge.push(P2(-c, {a - 1, b - 1}));
    }
    for(int i = 0; i < M + N; i++){
        p[i] = i;
        sz[i] = 1;
    }
    memset(parent, -1, sizeof(parent));
    for(int i = N; i < M + N; i++){
        P2 curr = edge.top();
        edge.pop();
        int first = find(curr.second.first), second = find(curr.second.second);
        if(first != second){
            merge(i, first);
            merge(i, second);
            adj[i].push_back(first);
            adj[i].push_back(second);
            min_value[i] = -curr.first;
            sz[i] = sz[first] + sz[second];
        }
    }
    for(int i = M + N - 1; i >= 0; i--){
        if(depth[i] == 0)
            dfs(i, 1);
    }
    for(int i = 1; i < MAX; i++)
        for(int j = 0; j < N + M; j++){
            if(parent[j][i - 1] == -1) continue;
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &a, &b);
        --a, --b;
        if(find(a) != find(b)){
            printf("-1\n");
            continue;
        }
        if(depth[a] > depth[b])
            swap(a, b);
        int diff = depth[b] - depth[a];
        for(int i = 0; diff; i++){
            if(diff % 2)
                b = parent[b][i];
            diff >>= 1;
        }
        if(a != b){
            for(int i = MAX - 1; i >= 0; i--){
                if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];
        }
        int lca = a;
        printf("%d %d\n", min_value[lca], sz[lca]);
    }
    return 0;
}