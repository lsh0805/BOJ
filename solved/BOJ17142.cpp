#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

const int SPACE = 0, WALL = 1, VIRUS = 2;

int N, M, m[51][51], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, space_cnt;
vector<P> virus;
vector<int> selected;

int simulate(){
    int ret = 0, cnt = 0;
    queue<P> q;
    bool visited[51][51] = {false};
    for(int i = 0; i < selected.size(); i++)
        if(selected[i]){
            q.push(virus[i]);
            visited[virus[i].f][virus[i].s] = true;
        }
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            P front = q.front();
            int curr_x = front.s, curr_y = front.f;
            q.pop();
            if(m[curr_y][curr_x] == SPACE)
                cnt++;
            for(int j = 0; j < 4; j++){
                int next_x = curr_x + dx[j], next_y = curr_y + dy[j];
                if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || visited[next_y][next_x] || m[next_y][next_x] == WALL)
                    continue;
                visited[next_y][next_x] = true;
                q.push(P(next_y, next_x));
            }
        }
        if(space_cnt == cnt)
            return ret;
        ret++;
    }
    return 2e9;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
            if(m[i][j] == VIRUS)
                virus.push_back(P(i, j));
            if(m[i][j] == SPACE)
                space_cnt++;
        }
    for(int i = 0; i < virus.size(); i++){
        if(virus.size() - i > M){
            selected.push_back(0);
        }else{
            selected.push_back(1);
        }
    }
    int ans = 2e9;
    do{
        ans = min(ans, simulate());
    }while(next_permutation(selected.begin(), selected.end()));

    if(ans == 2e9)
        cout << -1;
    else
        cout << ans;
}