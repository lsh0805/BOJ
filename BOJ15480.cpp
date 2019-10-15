#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 18;
int N, M, r, u, v, parents[100001][MAX], depth[100001];
vector<int> adj[100001];

void dfs(int curr, int d){
    depth[curr] = d;
    for(int next : adj[curr]){
        if(depth[next] > 0) continue;
        parents[next][0] = curr;
        dfs(next, d + 1);    
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0; diff; i++){
        if(diff % 2)
            v = parents[v][i];
        diff >>= 1;
    }
    int lca = u;
    if(u != v){
        for(int i = MAX - 1; i >= 0; i--){
            if(parents[u][i] != -1 && parents[u][i] != parents[v][i]){
                u = parents[u][i];
                v = parents[v][i];
            }
        }
        lca = parents[u][0];
    }
    return lca;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    memset(parents, -1, sizeof(parents));
    dfs(0, 1);
    for(int i = 1; i < MAX; i++)
        for(int j = 0; j < N; j++){
            if(parents[j][i - 1] == -1) continue;
            parents[j][i] = parents[parents[j][i - 1]][i - 1];
        }
    scanf("%d", &M);
    while(M--){
        scanf("%d %d %d", &r, &u, &v);
        r--, u--, v--;
        if(v == r  || u == r){
            printf("%d\n", r + 1);
            continue;
        }
        int w = LCA(u, v);
        if(r == w){
            printf("%d\n", w + 1);
            continue;
        }
        int w_r_lca = LCA(w, r);
        if(w_r_lca == r){
            printf("%d\n", w + 1);
            continue;
        }else if(w_r_lca != w){
            printf("%d\n", w + 1);
            continue;
        }
        int u_r_lca = LCA(u, r);
        int v_r_lca = LCA(v, r);
        if(w != u && w != v && u_r_lca != u && u_r_lca != r && v_r_lca != v && v_r_lca != r){
            printf("%d\n", depth[u_r_lca] > depth[v_r_lca] ? u_r_lca + 1 : v_r_lca + 1);
            continue;
        }else if((v_r_lca != r && v_r_lca != v) && depth[v_r_lca] > depth[w]){
            printf("%d\n", v_r_lca + 1);
            continue;
        }else if((u_r_lca != u && u_r_lca != v) && depth[u_r_lca] > depth[w]){
            printf("%d\n", u_r_lca + 1);
            continue;
        }else if((u_r_lca == r && v_r_lca == v) || (v_r_lca == r && u_r_lca == u)){
            printf("%d\n", r + 1);
            continue;
        }else if(u_r_lca == u && v_r_lca == v){
            printf("%d\n", depth[u] > depth[v] ? u + 1 : v + 1);
            continue;
        }else if(u_r_lca == u){
            printf("%d\n", u + 1);
            continue;
        }else if(v_r_lca == v){
            printf("%d\n", v + 1);
            continue;
        }
        printf("%d\n", r + 1);
    }
    return 0;
}