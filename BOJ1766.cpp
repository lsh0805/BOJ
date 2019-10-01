#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int indeg[32001], N, M, a, b;
priority_queue<int> pq;
vector<vector<int>> adj;

int main(){
    scanf("%d %d", &N, &M);
    adj.resize(N);
    for(int i = 0; i < M ; i++){
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int curr = -pq.top();
        pq.pop();
        printf("%d ", curr + 1);
        for(int next : adj[curr]){
            if(--indeg[next] == 0)
                pq.push(-next);
        }
    }
    return 0;
}