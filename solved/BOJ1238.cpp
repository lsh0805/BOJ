#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;
vector<vector<P>> adj;
int N, M, X, a, b, c, dist[1001][1001], back[1001], ans = 0;
priority_queue<P> pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> X;
    adj = vector<vector<P>>(N);
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(P(b, c));
    }
    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++)
            dist[i][k] = 2e9;
        dist[i][i] = 0;
        pq = priority_queue<P>();
        pq.push({0, i});
        while(!pq.empty()){
            P top = pq.top();
            pq.pop();
            int curr = top.second;
            int curr_dist = -top.first;
            if(curr_dist > dist[i][curr]) continue;
            if(curr == X - 1) break;
            for(P next_edge : adj[curr]){
                int next = next_edge.first;
                int next_cost = next_edge.second;
                
                if(dist[i][next] > next_cost + curr_dist){
                    dist[i][next] = next_cost + curr_dist;
                    pq.push(P(-dist[i][next], next));
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
        back[i] = 2e9;
    pq = priority_queue<P>();
    pq.push({0, X - 1});
    while(!pq.empty()){
        P top = pq.top();
        pq.pop();
        int curr = top.second;
        int curr_dist = -top.first;
        if(curr_dist > back[curr]) continue;
        for(P next_edge : adj[curr]){
            int next = next_edge.first;
            int next_cost = next_edge.second;
            
            if(back[next] > next_cost + curr_dist){
                back[next] = next_cost + curr_dist;
                pq.push(P(-back[next], next));
            }
        }
    }
    for(int i = 0; i < N; i++)
        ans = max(ans, dist[i][X - 1] + back[i]);
    cout << ans << "\n";
}