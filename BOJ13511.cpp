#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_D = 18;
int N, M, parent[100001][MAX_D], depth[100001], a, b, c, k, q;
long long cost[100001][MAX_D];
vector<pair<int, int>> adj[100001];

void dfs(int curr, int d){
    depth[curr] = d;
    for(auto next : adj[curr]){
        if(depth[next.first]) continue;
        parent[next.first][0] = curr;
        cost[next.first][0] = next.second;
        dfs(next.first, d + 1);
    }
}

int kth(int lca, int a, int b, int K, int cnt, int total_cnt){
    int curr;
    //올라가는 경우
    if(cnt > K){
        curr = a;
        for(int i = 0; K; i++, K >>= 1)
            if(K % 2)
                curr = parent[curr][i];
    }else if(cnt < K){ // 내려가는 경우
        K = total_cnt - K;
        curr = b;
        for(int i = 0; K; i++, K >>= 1)
            if(K % 2)
                curr = parent[curr][i];
    }else{ //k번째가 lca일 경우
        curr = lca;
    }
    return curr;
}
pair<int, pair<long long, pair<int, int>>> LCA(int a, int b){
    long long dist = 0;
    int left_cnt = 0, right_cnt = 0;
    if(depth[b] > depth[a]){
        int diff = depth[b] - depth[a];
        for(int i = 0; diff; i++){
            if(diff % 2){
                right_cnt += 1 << i;
                dist += cost[b][i];
                b = parent[b][i];
            }
            diff >>= 1;
        }
    }else{
      int diff = depth[a] - depth[b];
        for(int i = 0; diff; i++){
            if(diff % 2){
                left_cnt += 1 << i;
                dist += cost[a][i];
                a = parent[a][i];
            }
            diff >>= 1;
        }
    }
    if(a != b){
        for(int i = MAX_D - 1; i >= 0; i--){
            if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                left_cnt += 1 << i;
                right_cnt += 1 << i;
                dist += cost[a][i];
                dist += cost[b][i];
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        left_cnt++;
        right_cnt++;
        dist += cost[a][0];
        dist += cost[b][0];
        a = parent[a][0];
    }
    int lca = a;
    return {a, {dist, {left_cnt, right_cnt}}};
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    memset(parent, -1, sizeof(parent));
    dfs(0, 1);
    for(int i = 1; i < MAX_D; i++)
        for(int j = 0; j < N; j++){
            if(parent[j][i - 1] != -1){
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
                cost[j][i] = cost[j][i - 1] + cost[parent[j][i - 1]][i - 1];
            }
        }
    scanf("%d", &M);
    while(M--){
        scanf("%d %d %d", &q, &a, &b);
        pair<int, pair<long long, pair<int, int>>> p = LCA(a - 1, b - 1);
        int lca = p.first;
        long long dist = p.second.first;
        int a_cnt = p.second.second.first;
        int b_cnt = p.second.second.second;
        if(q == 1)
            printf("%lld\n", dist);
        else{
            scanf("%d", &k);
            printf("%d\n", kth(lca, a - 1, b - 1, k - 1, a_cnt, a_cnt + b_cnt) + 1);
        }
    }
    return 0;
}