#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define FOR(x, i, n) for(int x = i; x < n; x++)
#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, V, E, a, b, d[10001], id, ans;
bool visited[10001], cut[10001];
vector<int> adj[10001];

int dfs(int curr, bool r){
	visited[curr] = true;
	int ret = d[curr] = ++id;
	int cnt = 0;
	for(int next: adj[curr]){
		if(visited[next]) 
			ret = min(ret, d[next]);
		else{
			int res = dfs(next, false);
			ret = min(ret, res);
			if(!r && res >= d[curr] && !cut[curr]){
				cut[curr] = true;
				ans++;
			}
			cnt++;
		}
	}
	if(r && cnt >= 2 && !cut[curr]){
		cut[curr] = true;
		ans++;
	}
	return ret;
}

int main(){
    IO;
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < V; i++){
		if(!visited[i])
			dfs(i, true);
	}
	cout << ans << '\n';
	for(int i = 0; i < V; i++)
		if(cut[i])
		cout << i+1 << " ";
    return 0;
}