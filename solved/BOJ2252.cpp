#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, M, a, b, indeg[32001], visited[32001];
vector<vector<int>> adj;
vector<int> ans;
queue<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    adj = vector<vector<int>>(N);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);
        indeg[a]++;
    }
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            int front = q.front();
            q.pop();
            ans.push_back(front + 1);
            for(int next : adj[front]){
                if(visited[next] == true) continue;
                if(--indeg[next] == 0){
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}