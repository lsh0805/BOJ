#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100001;
int T, N, M, sccId[MAX_N], a, b, discoverd[MAX_N], cnt, indegree[MAX_N], visited[MAX_N];
bool finished[MAX_N];
stack<int> st;
vector<int> adj[MAX_N], scc_adj[MAX_N];
vector<vector<int>> SCC;

int dfs(int curr){
    st.push(curr);
    int res = (discoverd[curr] = ++cnt);
    for(int next : adj[curr]){
        if(discoverd[next] == 0){
            res = min(res, dfs(next));
        }else if(finished[next] == false){
            res = min(res, discoverd[next]);
        }
    }
    if(res == discoverd[curr]){
        vector<int> currSCC;
        while(true){
            int top = st.top();
            st.pop();
            currSCC.push_back(top);
            sccId[top] = SCC.size();
            finished[top] = true;
            if(top == curr) break; 
        }
        SCC.push_back(currSCC);
    }
    return res;
}

int sccDFS(int curr){
    visited[curr] = true;
    int ret = SCC[curr].size();
    for(int next : scc_adj[curr]){
        if(visited[next] == false)
            ret += sccDFS(next);
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(finished, false, sizeof(finished));
        memset(discoverd, 0, sizeof(discoverd));
        memset(indegree, 0, sizeof(indegree));
        memset(visited, false, sizeof(visited));
        memset(sccId, 0, sizeof(sccId));
        scanf("%d %d", &N, &M);
        for(int i = 0; i < MAX_N; i++){
            adj[i] = vector<int>();
            scc_adj[i] = vector<int>();
        }
        SCC = vector<vector<int>>();
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
        }
        for(int i = 0; i < N; i++){
            if(discoverd[i] == 0)
                dfs(i);
        }
        for(int i = 0; i < N; i++){
            for(int next : adj[i]){
                if(sccId[i] != sccId[next]){
                    scc_adj[sccId[i]].push_back(sccId[next]);
                    indegree[sccId[next]]++;
                }
            }
        }
        int start;
        for(int i = 0; i < SCC.size(); i++){
            if(indegree[i] == 0){
                start = i;
                break;
            }
        }
        int sum = sccDFS(start);
        if(sum == N){
            sort(SCC[start].begin(), SCC[start].end());
            for(int i = 0; i < SCC[start].size(); i++)
                printf("%d\n", SCC[start][i]);
            putchar('\n');
        }else
            printf("Confused\n\n");
    }

    return 0;
}