#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, M, G, R, m[51][51], copy_m[51][51], visited[51][51], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
const int LAKE = 0, CANT = 1, CAN = 2, GREEN = 3, RED = -3, FLOWER = 4;
vector<pair<int, int>> v;

int getCount(){
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            m[i][j] = copy_m[i][j];
            if(m[i][j] == GREEN || m[i][j] == RED)
                q.push(mp(i, j));
        }
    int time = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            pair<int, int> front = q.front();
            q.pop();
            int curr_x = front.se, curr_y = front.fi;
            if(m[curr_y][curr_x] == GREEN || m[curr_y][curr_x] == RED){
                for(int j = 0; j < 4; j++){
                    int x = curr_x + dx[j], y = curr_y + dy[j];
                    if(x < 0 || x >= M || y < 0 || y >= N || m[y][x] == LAKE || m[y][x] == FLOWER) continue;
                    if(m[y][x] == -m[curr_y][curr_x] && visited[y][x] == time){
                        m[y][x] = FLOWER;
                        ret++;
                    }else if(m[y][x] == CAN || m[y][x] == CANT){
                        m[y][x] = m[curr_y][curr_x];
                        visited[y][x] = time;
                        q.push(mp(y, x));
                    }
                }
            }
        }
        time++;
    }
    return ret;
}

int solve(int g, int r, int curr){
    int ret = 0;
    if(g == G && r == R)
        return getCount();
    if(g > G || r > R || curr == v.size())
        return 0;
    copy_m[v[curr].fi][v[curr].se] = GREEN;
    ret = solve(g + 1, r, curr + 1);
    copy_m[v[curr].fi][v[curr].se] = RED;
    ret = max(ret, solve(g, r + 1, curr + 1));
    copy_m[v[curr].fi][v[curr].se] = CAN;
    return ret = max(ret, solve(g, r, curr + 1));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
            copy_m[i][j] = m[i][j];
            if(m[i][j] == CAN)
                v.push_back(mp(i, j));
        }
    cout << solve(0, 0, 0);
    return 0;
}