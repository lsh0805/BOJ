
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

const int MAX_N = 500001;
int N, M, P, S, cost[MAX_N], sccId[MAX_N], a, b, discoverd[MAX_N], cnt, sccCost[MAX_N], ans, dist[MAX_N];
bool hasRest[MAX_N], sccHasRest[MAX_N], finished[MAX_N];
vector<int> adj[MAX_N], scc_adj[MAX_N];
vector<vector<int>> SCC;
stack<int> st;

int sccGetByDFS(int curr){
    st.push(curr);
    int res = (discoverd[curr] = ++cnt);
    for(int next : adj[curr]){
        if(discoverd[next] == 0){
            res = min(res, sccGetByDFS(next));
        }else if(!finished[next]){
            res = min(res, discoverd[next]);
        }
    }
    if(res == discoverd[curr]){
        vector<int> currSCC;
        int sz = SCC.size();
        while(true){
            int t = st.top();
            st.pop();
            currSCC.push_back(t);
            sccId[t] = sz;
            finished[t] = true;
            if(hasRest[t]) sccHasRest[sz] = true;
            sccCost[sz] += cost[t];
            if(t == curr) break;
        }
        SCC.push_back(currSCC);
    }
    return res;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        adj[a - 1].push_back(b - 1);
    }
    for(int i = 0; i < N; i++)
        scanf("%d", cost + i);
    scanf("%d %d", &S, &P);
    for(int i = 0; i < P; i++){
        scanf("%d", &a);
        hasRest[a - 1] = true;
    }
    for(int i = 0; i < N; i++)
        if(discoverd[i] == 0)
            sccGetByDFS(i);
    for(int i = 0; i < N; i++){
        for(int next : adj[i]){
            if(sccId[next] != sccId[i])
                scc_adj[sccId[i]].push_back(sccId[next]);
        }
    }
    priority_queue<pair<int, int>> pq;
    pq.push({sccCost[sccId[S - 1]], sccId[S - 1]});
    dist[sccId[S - 1]] = sccCost[sccId[S - 1]];
    while(!pq.empty()){
        pair<int ,int> curr = pq.top();
        pq.pop();
        int curr_id = curr.second;
        int curr_dist = curr.first;
        if(dist[curr_id] > curr_dist) continue;
        if(sccHasRest[curr_id] && curr_dist > ans)
            ans = curr_dist;
        for(int next_id : scc_adj[curr_id]){
            int next_dist = curr_dist + sccCost[next_id];
            if(dist[next_id] < next_dist){
                dist[next_id] = next_dist;
                pq.push({next_dist, next_id});
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}