#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, a, b, c;
long long dist[10001][21];
const long long INF = 10e11;
typedef pair<long long, pair<int, int>> P;
typedef pair<int, int> P1;
priority_queue<P> pq;
vector<vector<P1>> adj;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i < N; i++)
        for(int j = 0; j <= K; j++)
            dist[i][j] = INF;
    adj = vector<vector<P1>>(N);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pq.push({0, {K, 0}});
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        int curr = p.second.second;
        long long curr_dist = -p.first;
        int curr_k = p.second.first;
        if(curr_dist > dist[curr][curr_k])
            continue;
        for(P1 np : adj[curr]){
            int next = np.first;
            long long next_dist = np.second * 1LL + dist[curr][curr_k];
            if(curr_k > 0 && dist[curr][curr_k] < dist[next][curr_k - 1]){
                dist[next][curr_k - 1] = dist[curr][curr_k];
                pq.push({-dist[curr][curr_k], {curr_k - 1, next}});
            }
            if(next_dist < dist[next][curr_k]){
                dist[next][curr_k] = next_dist;
                pq.push({-next_dist, {curr_k, next}});
            }
            
        }
    }
    long long ans = INF;
    for(int i = 0; i <= K; i++)
        ans = min(ans, dist[N-1][i]);
    printf("%lld", ans);
    return 0;
}