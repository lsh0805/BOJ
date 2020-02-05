#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 16;
int N, a, b, M, parent[30001][MAX], dest, curr, depth[30001], ans;
bool visited[40001];
vector<int> adj[40001];

void dfs(int curr, int d){
    visited[curr] = true;
    depth[curr] = d;
    for(int next : adj[curr]){
        if(visited[next]) continue;
        parent[next][0] = curr;
        dfs(next, d + 1);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &a, &b);
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    memset(parent, -1, sizeof(parent));
    dfs(0, 0);
    for(int i = 1; i < MAX; i++)
        for(int j = 0; j < N; j++){
            if(parent[j][i - 1] == -1) continue;
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    scanf("%d", &M);
    while(M--){
        scanf("%d", &dest);
        dest--;
        a = curr, b = dest;
        if(depth[a] > depth[b])
            swap(a, b);
        int diff = depth[b] - depth[a];
        for(int i = 0; diff; i++){
            if(diff % 2)
                b = parent[b][i];
            diff /= 2;
        }
        int lca;
        if(a != b){
            for(int i = MAX - 1; i >= 0; i--){
                if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                    a = parent[a][i];
                    b = parent[b][i];
                }
                lca = parent[a][i];
            }
        }else{
            lca = a;
        }
        ans += depth[curr] + depth[dest] - depth[lca] * 2;
        curr = dest;
    }
    printf("%d", ans);
    return 0;
}