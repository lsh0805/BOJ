#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> P2;
typedef pair<int, int> P;

const int INF = 1e9, MOD = 1e9 + 7;
int N, M, a, b, c, dist[1501], cnt[5001], prev_edge[1501];
vector<P2> adj[1501];
P edge[5001];

void dijkstra(int curr){
    for(int i = 0; i < N; i++){
        dist[i] = INF;
        prev_edge[i] = -1;
    }
    priority_queue<P> pq;
    pq.push(P(0, curr));
    dist[curr] = 0;
    while(!pq.empty()){
        int curr_dist = -pq.top().first;
        int curr_v = pq.top().second;
        pq.pop();
        if(curr_dist > dist[curr_v]) continue;
        for(P2 next : adj[curr_v]){
            int next_dist = next.first + curr_dist;
            int next_v = next.second.first;
            int next_edge = next.second.second;
            if(dist[next_v] > next_dist){
                prev_edge[next_v] = next_edge;
                dist[next_v] = next_dist;
                pq.push(P(-next_dist, next_v));
            }
        }
    }
    for(int i = 0; i < N; i++){
        int curr_v = i;
        if(curr == i) continue;
        while(curr_v != curr){
            int edge_idx = prev_edge[curr_v];
            if(edge_idx == -1) break;
            cnt[edge_idx]++;
            cnt[edge_idx] %= MOD;
            curr_v = edge[edge_idx].first;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a - 1].push_back(P2(c, {b - 1, i}));
        edge[i] = P(a - 1, b - 1);
    }
    for(int i = 0; i < N; i++)
        dijkstra(i);
    for(int i = 0; i < M; i++)
        printf("%d\n", cnt[i] % MOD);
    return 0;
}