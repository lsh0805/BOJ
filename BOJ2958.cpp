#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> P2;
typedef pair<int, int> P;

const int INF = 1e9, MOD = 1e9 + 7;
int N, M, a, b, c, dist[1501], cnt[5001], in[1501], out[1501];
vector<P2> adj[1501];

void dfs(int curr, int d){
    if(out[curr] != 0) return;
    out[curr] = 1;
    for(P2 next : adj[curr]){
        int next_dist = next.first + d;
        int next_v = next.second.first;
        int next_edge = next.second.second;
        if(dist[next_v] != next_dist) continue;
        dfs(next_v, next_dist);
        out[curr] = out[curr] + out[next_v];
        cnt[next_edge] = (cnt[next_edge] + in[curr] * out[next_v]) % MOD;
    }
}

void dijkstra(int curr){
    for(int i = 0; i < N; i++){
        dist[i] = INF;
        in[i] = 0;
        out[i] = 0;
    }
    priority_queue<P> pq;
    pq.push(P(0, curr));
    dist[curr] = 0;
    in[curr] = 1;
    while(!pq.empty()){
        int curr_dist = -pq.top().first;
        int curr_v = pq.top().second;
        pq.pop();
        if(curr_dist > dist[curr_v]) continue;
        for(P2 next : adj[curr_v]){
            int next_dist = next.first + curr_dist;
            int next_v = next.second.first;
            int next_edge = next.second.second;
            if(dist[next_v] >= next_dist){
                if(dist[next_v] > next_dist){
                    in[next_v] = 0;
                    dist[next_v] = next_dist;
                    pq.push(P(-next_dist, next_v));
                }
                in[next_v] = (in[curr_v] + in[next_v]) % MOD;
            }
        }
    }
    dfs(curr, 0);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a - 1].push_back(P2(c, {b - 1, i}));
    }
    for(int i = 0; i < N; i++)
        dijkstra(i);
    for(int i = 0; i < M; i++)
        printf("%d\n", cnt[i] % MOD);
    return 0;
}