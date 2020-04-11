#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

const int MAX_D = 17;
int T, N, M, a, b, ans, p[50001][MAX_D], d[50001];
vector<vector<int>> adj;
bool visited[50001];

void dfs(int curr, int depth){
    visited[curr] = true;
    d[curr] = depth;
    for(int next: adj[curr])
        if(!visited[next]){
            p[next][0] = curr;
            dfs(next, depth + 1);
        }
}

int lca(int a, int b){
    if (d[a] < d[b])
        swap(a, b);
    int diff = d[a] - d[b];
    for(int i = 0; diff; i++){
        if(diff % 2)
            a = p[a][i];
        diff /= 2;
    }
    if(a != b){
        for(int i = MAX_D - 1; i >= 0; i--){
            if(p[a][i] != p[b][i]){
                a = p[a][i];
                b = p[b][i];
            }
        }
        a = p[a][0];
    }
    return a;
}

int main()
{
    cin >> N;
    adj = vector<vector<int>>(N);
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    for (int j = 1; j < MAX_D; j++)
    {
        for (int i = 1; i < N; i++)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    cin >> M;
    while(M--){
        cin >> a >> b;
        cout << lca(a - 1, b - 1) + 1 << '\n';
    }
    return 0;
}