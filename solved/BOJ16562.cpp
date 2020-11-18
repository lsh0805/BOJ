#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, k, A[10001], v, w, visited[10001], cnt, ans;
vector<vector<int>> f;

int dfs(int curr){
    cnt++;
    int ret = A[curr];
    visited[curr] = true;
    for(int next : f[curr]){
        if(visited[next]) continue;
        ret = min(ret, dfs(next));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> k;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    f = vector<vector<int>>(N);
    for(int i = 0; i < M; i++){
        cin >> v >> w;
        v--, w--;
        f[v].push_back(w);
        f[w].push_back(v);
    }
    for(int i = 0; i < N; i++)
        if(!visited[i])
            ans += dfs(i);
    if(cnt != N || k < ans){
        cout << "Oh no";
        return 0;
    }else{
        cout << ans;
    }
}