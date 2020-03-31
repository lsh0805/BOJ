#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, adj[101][101], cnt[101];

int main(){
    cin >> N >> M;

    while(M--){
        cin >> a >> b;
        adj[a - 1][b - 1] = true;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(!adj[i][k]) continue;
            for(int j = 0; j < N; j++){
                adj[i][j] |= adj[i][k] & adj[k][j];
            }
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(adj[i][j]){
                cnt[i]++;
                cnt[j]++;
            }
        }
    for(int i = 0; i < N; i++)
        cout << N - (cnt[i] + 1) << '\n';
    return 0;
}