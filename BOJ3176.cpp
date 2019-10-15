#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 18;
int N, a, b, c, K, depth[100001], parent[100001][MAX], min_value[100001][MAX], max_value[100001][MAX];
typedef pair<int, int> P;
vector<P> adj[100001];

void dfs(int curr, int d){
    depth[curr] = d;
    for(P next : adj[curr]){
        if(depth[next.first] > 0) continue;
        parent[next.first][0] = curr;
        min_value[next.first][0] = next.second;
        max_value[next.first][0] = next.second;
        dfs(next.first, d + 1);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        adj[a].push_back(P(b, c));
        adj[b].push_back(P(a, c));
    }
    memset(parent, -1, sizeof(parent));
    dfs(0, 1);
    for(int i = 1; i < MAX; i++)
        for(int j = 0; j < N; j++){
            if(parent[j][i - 1] == -1) continue;
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
            min_value[j][i] = min(min_value[j][i - 1], min_value[parent[j][i - 1]][i - 1]);
            max_value[j][i] = max(max_value[j][i - 1], max_value[parent[j][i - 1]][i - 1]);
        }
    scanf("%d", &K);
    while(K--){
        scanf("%d %d", &a, &b);
        --a, --b;
        if(depth[a] > depth[b])
            swap(a, b);
        int diff = depth[b] - depth[a];
        int min_ans = 1e9, max_ans = 0;
        for(int i = 0; diff; i++){
            if(diff % 2){
                
                min_ans = min(min_ans, min_value[b][i]);
                max_ans = max(max_ans, max_value[b][i]);
                b = parent[b][i];
            }
            diff >>= 1;
        }
        if(a != b){
            for(int i = MAX - 1; i >= 0; i--){
                if(parent[a][i] != - 1 && parent[b][i] != parent[a][i]){
                    min_ans = min({min_ans, min_value[a][i], min_value[b][i]});
                    max_ans = max({max_ans, max_value[a][i], max_value[b][i]});
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            min_ans = min({min_ans, min_value[a][0], min_value[b][0]});
            max_ans = max({max_ans, max_value[a][0], max_value[b][0]});
            a = parent[a][0];
        }
        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}