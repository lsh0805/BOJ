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

int N, m[51][51], T, R, C, dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
P p;

void spread(){
	int temp[51][51] = {0, };
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(m[i][j] <= 0) continue;
			int cnt = 0;
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k], nx = j + dx[k];
				if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
				if(m[ny][nx] == -1) continue;
				temp[ny][nx] += m[i][j] / 5;
				cnt++;
			}
			m[i][j] -= m[i][j] / 5 * cnt;
		}
	}
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			m[i][j] += temp[i][j];
		}
	}
}

void blow(){
	for(int j = 0; j < 2; j++){
		int x = p.se + 1, y = p.fi + (j == 1), previous = -1, temp = -1;
		for(int i = 0; i < 4;){
			int nx = x + dx[i], ny = y + dy[i] * (j == 0 ? 1 : -1);
			if(ny < 0 || ny >= R || nx < 0 || nx >= C){
				i++;
				continue;
			}
			if(m[y][x] == -1) break;
			if(previous == -1){
				previous = m[y][x];
				m[y][x] = 0;
			}else{
				temp = m[y][x];
				m[y][x] = previous;
				previous = temp;
			}
			x = nx, y = ny;
		}
	}
}

int simulate(){
	int ret = 0;
	while(T--){
		spread();
		blow();
	}
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(m[i][j] > 0) ret += m[i][j];
	return ret;
}

int main(){
    IO;
	cin >> R >> C >> T;
	p = {-1, -1};
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> m[i][j];
			if(m[i][j] == -1 && p == P(-1, -1)){
				p = {i, j};
			}
		}
	}
	cout << simulate();
    return 0;
}