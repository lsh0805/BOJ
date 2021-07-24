#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define dir first
#define spd second.first.first
#define weight second.first.second
#define x second.second.first
#define y second.second.second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<int, pair<P, P>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int R, C, M, r, c, s, d, z, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};
P m[101][101];

vector<P2> shark;

void clear()
{
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			m[i][j] = P(-1, 0);
}

PP moving(P2 shark){
	for(int cnt = shark.spd; cnt > 0; cnt--)
	{
		int nx = shark.x + dx[shark.dir];
		int ny = shark.y + dy[shark.dir];
		if(nx < 0 || nx >= C || ny < 0 || ny >= R)
		{
			if(shark.dir % 2)
				shark.dir--;
			else
				shark.dir++;
		}
		shark.x += dx[shark.dir];
		shark.y += dy[shark.dir];
	}
	return PP(shark.dir, P(shark.x, shark.y));
}

void shark_move()
{
	clear();
	for(int i = 0; i < shark.size(); i++)
	{
		if(shark[i].dir == -1) continue;
		PP pos = moving(shark[i]);
		shark[i].dir = pos.fi;
		shark[i].x = pos.se.fi;
		shark[i].y = pos.se.se;
		if (m[shark[i].y][shark[i].x].fi == -1){
			m[shark[i].y][shark[i].x].se = shark[i].weight;
			m[shark[i].y][shark[i].x].fi = i;
		}
		else if (m[shark[i].y][shark[i].x].se < shark[i].weight){
			m[shark[i].y][shark[i].x].se = shark[i].weight;
			shark[m[shark[i].y][shark[i].x].fi].dir = -1;
			m[shark[i].y][shark[i].x].fi = i;
		}
		else {
			shark.erase(shark.begin() + i);
			i--;
		}
	}
}

int simulate(int pos){
	int ret = 0;
	if(pos == C - 1) return 0;
	pos++;
	int target_shark = -1, _min = INF;
	for(int i = 0; i < shark.size(); i++)
	{
		if(shark[i].dir == -1) continue;
		if(shark[i].x == pos && _min > shark[i].y)
		{
			_min = shark[i].y;
			target_shark = i;
		}
	}
	if (target_shark != -1)
	{
		ret = shark[target_shark].weight;
		shark[target_shark].dir = -1;
	}
	shark_move();
	return ret + simulate(pos);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> R >> C >> M;
	shark.resize(M);
	for(int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		shark[i].y = r - 1;
		shark[i].x = c - 1;
		shark[i].dir = d - 1;
		if(shark[i].dir < 2)
			shark[i].spd = s % ((R - 1)*2);
		else
			shark[i].spd = s % ((C - 1)*2);
		shark[i].weight = z;
	}
	cout << simulate(-1);
    return 0;
}