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

int N, m[20][20], idx[20][20], cnt, sz = 2, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool visited[20][20], killed[20][20];
P curr;
vector<P2> v;

P2 find_target(){
	memset(visited, false, sizeof(visited));
	int ty = -1, tx = -1;
	queue<P> q;
	int d = 0;
	bool flag = false;
	q.push(curr);
	visited[curr.first][curr.second] = true;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; i++){
			P front = q.front();
			q.pop();
			int c_x = front.second;
			int c_y = front.first;
			if(m[c_y][c_x] != 9 && m[c_y][c_x] != 0 && m[c_y][c_x] < sz && !killed[c_y][c_x]){
				flag = true;
				if(ty == -1)
					ty = c_y, tx = c_x;
				else{
					if(ty > c_y){
						ty = c_y, tx = c_x;
					}else if(ty == c_y){
						if(tx > c_x)
							ty = c_y, tx = c_x;
					}
				}
			}
			for(int j = 0; j < 4; j++){
				int n_x = c_x + dx[j];
				int n_y = c_y + dy[j];
				if(n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
				if(visited[n_y][n_x]) continue;
				if(m[n_y][n_x] != 9 && m[n_y][n_x] > sz && !killed[n_y][n_x]) continue;
				q.push(P(n_y, n_x));
				visited[n_y][n_x] = true;
			}
		}
		if(flag) break;
		d++;
	}
	return P2(d, P(ty, tx));
}

int solve(int t){
	
	P2 res = find_target();
	P target = res.second;
	int d = res.first;
	if(target.first != -1){
		curr = target;
		m[target.fi][target.se] = 0;
		if(++cnt == sz){
			cnt = 0;
			sz++;
		}
		return solve(t + d);
	}else{
		return t;
	}
}

int main(){
    IO;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
			if(m[i][j] == 9){
				curr = P(i, j);
			}
		}
	}
	cout << solve(0);
    return 0;
}