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

const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
int N, M, m[8][8], o[8][8], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool visited[8][8][8];
vector<int> v[5];
vector<P> cctv;

void fill(int x, int y, int idx, int dir){
	int ny = y, nx = x;
	while(!(ny < 0 || ny >= N || nx < 0 || nx >= M) && m[ny][nx] != -1){
		if(m[ny][nx] == 20){
			ny += dy[dir];
			nx += dx[dir];
			continue;
		}
		visited[idx][ny][nx] = true;
		m[ny][nx] = 20;
		ny += dy[dir];
		nx += dx[dir];	
	}
}

void un_fill(int x, int y, int idx, int dir){
	int ny = y, nx = x;
	while(!(ny < 0 || ny >= N || nx < 0 || nx >= M) && m[ny][nx] != -1){
		if(visited[idx][ny][nx]) m[ny][nx] = 0;
		visited[idx][ny][nx] = false;
		ny += dy[dir];
		nx += dx[dir];	
	}
}

void spread(int dir, int idx){
	if(dir == 1){
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 2){
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 3){
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 4){
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 5){
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 6){
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 7){
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 8){
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 9){
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 10){
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 11){
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 12){
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 13){
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 14){
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 15){
		fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}
}

void back(int dir, int idx){
	if(dir == 1){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 2){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 3){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 4){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 5){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 6){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 7){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 8){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 9){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 10){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 11){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
	}else if(dir == 12){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
	}else if(dir == 13){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}else if(dir == 14){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
	}else if(dir == 15){
		un_fill(cctv[idx].se, cctv[idx].fi, idx, UP);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, RIGHT);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, DOWN);
		un_fill(cctv[idx].se, cctv[idx].fi, idx, LEFT);
	}
}

int test(){
	int ret = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(m[i][j] == 0) ret++;
		}
	}
	return ret;
}

int simulate(int idx){
	int ret = 2e9;
	if(idx == cctv.size())
		return test();

	for(int i = 0; i < v[o[cctv[idx].fi][cctv[idx].se] - 1].size(); i++){
		spread(v[o[cctv[idx].fi][cctv[idx].se] - 1][i], idx);
		ret = min(ret, simulate(idx + 1));
		back(v[o[cctv[idx].fi][cctv[idx].se] - 1][i], idx);
	}

	return ret;
}

int main(){
    IO;
	v[0].push_back(1);
	v[0].push_back(2);
	v[0].push_back(3);
	v[0].push_back(4);

	v[1].push_back(5);
	v[1].push_back(6);

	v[2].push_back(7);
	v[2].push_back(8);
	v[2].push_back(9);
	v[2].push_back(10);

	v[3].push_back(11);
	v[3].push_back(12);
	v[3].push_back(13);
	v[3].push_back(14);

	v[4].push_back(15);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> o[i][j];
			if(o[i][j] == 6){
				o[i][j] = -1;
				m[i][j] = -1;
			}
			else if(o[i][j] != 0) cctv.push_back(P(i, j));
		}
	}
	cout << simulate(0) << "\n";
    return 0;
}