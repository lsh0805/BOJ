#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_N = 100001;
int N, M, a, b, discoverd[MAX_N], finished[MAX_N], cnt, sccId[MAX_N], outDegree[MAX_N];
vector<vector<int>> SCC;
vector<int> adj[MAX_N], scc_adj[MAX_N], ans;
stack<int> st;

int dfs(int curr){
    st.push(curr);
    int ret = (discoverd[curr] = ++cnt);
    for(int next : adj[curr]){
        if(discoverd[next] == 0){
            ret = min(ret, dfs(next));
        }else if(finished[next] == false){
            ret = min(ret, discoverd[next]);
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
    while(true){
        scanf("%d", &N);
        if(N == 0) break;
        scanf("%d", &M);
        memset(discoverd, 0, sizeof(discoverd));
        memset(finished, 0, sizeof(finished));
        memset(sccId, 0, sizeof(sccId));
        memset(outDegree, 0, sizeof(outDegree));
        SCC = vector<vector<int>>(0);
        for(int i = 0; i < N; i++){
            scc_adj[i] = vector<int>();
            adj[i] = vector<int>();
        }
        ans = vector<int>();
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            adj[a - 1].push_back(b - 1);
        }
        for(int i = 0; i < N; i++){
            if(discoverd[i] == 0)
                dfs(i);
        }
        for(int i = 0; i < N; i++){
            for(int next : adj[i]){
                if(sccId[i] != sccId[next])
                    outDegree[sccId[i]]++;
            }
        }
        for(int i = 0; i < SCC.size(); i++){
            if(outDegree[i] == 0){
                for(int j = 0; j < SCC[i].size(); j++)
                    ans.push_back(SCC[i][j] + 1);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}