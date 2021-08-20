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

int N, L, R, m[51][51], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool visited[51][51];
queue<P> q;

int dfs(int x, int y){
	int ret = m[y][x];
	q.push(P(y, x));
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
		int diff = abs(m[y][x] - m[ny][nx]);
		if(L <= diff && diff <= R)
			ret += dfs(nx, ny);
	}
	return ret;
}

void update(int val){
	int qsize = q.size();
	while(!q.empty()){
		P front = q.front();
		q.pop();
		m[front.fi][front.se] = val / qsize;
	}
}

int main(){
    IO;
	cin >> N >> L >> R;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
		}
	}
	int ans = 0;
	while(true){
		bool flag = false;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!visited[i][j]){
					int res = dfs(j, i);
					if(q.size() != 1){
						flag = true;
						update(res);
					}
					q = queue<P>();
				}
			}
		}
		memset(visited, false, sizeof(visited));
		if(!flag) break;
		ans++;
	}
	cout << ans << "\n";
    return 0;
}