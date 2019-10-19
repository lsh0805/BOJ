#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dist[101][101], N, M, a, b, visited[101];
const int INF = 1e8;
vector<vector<int>> v;
vector<int> ans;

void dfs(int curr, int id){
    visited[curr] = true;
    v[id].push_back(curr);
    for(int next = 0; next < N; next++)
        if(dist[curr][next] != INF && !visited[next])
            dfs(next, id);
}

int main(){
    scanf("%d %d", &N, &M);
    v = vector<vector<int>>(N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dist[i][j] = INF;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        --a, --b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(dist[i][k] == INF)
                continue;
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    int component_size = 0;
    for(int i = 0; i < N; i++)
        if(!visited[i])
            dfs(i, component_size++);
    printf("%d\n", component_size);
    for(int i = 0; i < component_size; i++){
        int m = INF, represent = 0;
        for(int k = 0; k < v[i].size(); k++){
            int delay = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(k == j) continue;
                delay = max(delay , dist[v[i][j]][v[i][k]]);
            }
            if(m > delay){
                m = delay;
                represent = v[i][k] + 1;
            }
        }
        ans.push_back(represent);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}