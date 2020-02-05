#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> P;
const int MAX_D = 17;
int N, M, parent[40001][MAX_D], dist[40001][MAX_D], a, b, c, visited[40001], depth[40001];
vector<P> adj[40001];
void makeTree(int curr, int cnt){
    depth[curr] = cnt;
    for(P next : adj[curr]){
        if(depth[next.first] > 0) continue;
        parent[next.first][0] = curr;
        dist[next.first][0] = next.second;
        makeTree(next.first, cnt + 1);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a - 1].push_back(P(b - 1, c));
        adj[b - 1].push_back(P(a - 1, c));
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < MAX_D; j++)
            parent[i][j] = -1;
    makeTree(0, 1);
    for(int i = 0; i < MAX_D - 1; i++)
        for(int j = 1; j < N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i + 1] = parent[parent[j][i]][i];
            dist[j][i + 1] = dist[j][i] + dist[parent[j][i]][i];
        }
    scanf("%d", &M);
    while(M--){
        scanf("%d %d", &a, &b);
        a--, b--;
        int d = 0;
        if(depth[a] != depth[b]){
            if(depth[a] > depth[b])
                swap(a, b);
            int diff = depth[b] - depth[a];
            for(int i = 0; diff; i++){
                if(diff % 2){
                    d += dist[b][i];
                    b = parent[b][i];
                }
                diff /= 2;
            }
        }
        if(a != b){
            for(int k = MAX_D - 1; k >= 0; k--){
                if(parent[a][k] != -1 && (parent[a][k] != parent[b][k])){
                    d += dist[a][k] + dist[b][k];
                    a = parent[a][k];
                    b = parent[b][k];
                }
            }
            d += dist[a][0] + dist[b][0];
            a = parent[a][0];
        }
        printf("%d\n", d);
    }

    return 0;
}