#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_N = 301;
int T, N, M, adj[MAX_N][MAX_N], indeg[MAX_N], discoverd[MAX_N], finished[MAX_N], cnt, sccId[MAX_N], scc_adj[MAX_N][MAX_N], visited[MAX_N];
vector<vector<int>> SCC;
vector<pair<int, int>> ans;
stack<int> st;
typedef pair<int, int> P;
P p;

int dfs(int curr){
    st.push(curr);
    int ret = (discoverd[curr] = ++cnt);
    for(int next = 0; next < N; next++){
        if(adj[curr][next]){
            if(discoverd[next] == 0){
                ret = min(ret, dfs(next));
            }else if(finished[next] == false){
                ret = min(ret, discoverd[next]);
            }
        }
    }
    if(ret == discoverd[curr]){
        vector<int> currSCC;
        while(true){
            int top = st.top();
            st.pop();
            currSCC.push_back(top);
            finished[top] = true;
            sccId[top] = SCC.size();
            if(top == curr) break;
        }
        SCC.push_back(currSCC);
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(discoverd, 0, sizeof(discoverd));
        memset(finished, 0, sizeof(finished));
        memset(sccId, 0, sizeof(sccId));
        memset(adj, 0, sizeof(adj));
        memset(scc_adj, 0, sizeof(scc_adj));
        memset(indeg, 0, sizeof(indeg));
        SCC = vector<vector<int>>();
        ans = vector<pair<int, int>>();
        cnt = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%1d", &adj[i][j]);
                if(i == j)
                    adj[i][j] = false;
            }
        }
        for(int i = 0; i < N; i++)
            if(discoverd[i] == 0)
                dfs(i);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(adj[i][j]){
                    if(sccId[i] != sccId[j] && !scc_adj[sccId[i]][sccId[j]]){
                        scc_adj[sccId[i]][sccId[j]] = true;
                        indeg[sccId[j]]++;
                    }
                }
            }
        }
        for(int i = 0; i < SCC.size(); i++){
            if(SCC[i].size() > 1){
                for(int j = 0; j < SCC[i].size() - 1; j++)
                    ans.push_back(make_pair(SCC[i][j], SCC[i][j + 1]));
                ans.push_back(make_pair(SCC[i][SCC[i].size() - 1], SCC[i][0]));
            }
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        printf("\n");
    }
    return 0;
}