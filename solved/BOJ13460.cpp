#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;
typedef pair<pair<int, int>, pair<int, int>> PP;
int N, M, r_x, r_y, b_x, b_y, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, ans = -1;
char m[11][11];
queue<PP> q;

PP proceed(PP status, int dir){
    P red = status.x;
    P blue = status.y;
    int first_move = 0;
    bool red_fall = false;
    bool blue_fall = false;
    // 누구부터 움직일 지
    switch (dir)
    {
    case 0:
        first_move = red.y < blue.y ? 0 : 1;
        break;
    case 1:
        first_move = red.y >= blue.y ? 0 : 1;
        break;
    case 2:
        first_move = red.x < blue.x ? 0 : 1;
        break;
    case 3:
        first_move = red.x >= blue.x ? 0 : 1;
        break;
    default:
        break;
    } 

    if(first_move == 0){
        // red
        while(true){
            int nx = red.x + dx[dir];
            int ny = red.y + dy[dir];
            if(m[ny][nx] == 'O'){
                red_fall = true;
                red = P(-1, -1);
                break;
            }
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || P(nx, ny) == blue ||m[ny][nx] != '.') break;
            red.x = nx;
            red.y = ny;
        }
        // blue
        while(true){
            int nx = blue.x + dx[dir];
            int ny = blue.y + dy[dir];
            if(m[ny][nx] == 'O'){
                blue_fall = true;
                blue = P(-1, -1);
                break;
            }
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || P(nx, ny) == red || m[ny][nx] != '.') break;
            blue.x = nx;
            blue.y = ny;
        }
    }else{
        // blue
        while(true){
            int nx = blue.x + dx[dir];
            int ny = blue.y + dy[dir];
            if(m[ny][nx] == 'O'){
                blue_fall = true;
                blue = P(-1, -1);
                break;
            }
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || P(nx, ny) == red || m[ny][nx] != '.') break;
            blue.x = nx;
            blue.y = ny;
        }
        // red
        while(true){
            int nx = red.x + dx[dir];
            int ny = red.y + dy[dir];
            if(m[ny][nx] == 'O'){
                red_fall = true;
                red = P(-1, -1);
                break;
            }
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || P(nx, ny) == blue ||m[ny][nx] != '.') break;
            red.x = nx;
            red.y = ny;
        }
    }
    if(blue_fall == true) return PP(P(-2, -2), P(-2, -2));
    if(red_fall == true) return PP(P(-1, -1), P(-1, -1));
    else return PP(red, blue);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
            if(m[i][j] == 'R'){
                m[i][j] = '.';
                r_x = j, r_y = i;
            }
            if(m[i][j] == 'B'){
                m[i][j] = '.';
                b_x = j, b_y = i;
            }
        }
    }
    q.push(PP(P(r_x, r_y), P(b_x, b_y)));
    for(int i = 0; i < 10 && !q.empty() && ans == -1; i++){
        int qsize = q.size();
        for(int j = 0; j < qsize; j++){
            PP curr = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                PP result = proceed(curr, k);
                if(result.x.x == -1){
                    ans = i + 1;
                    break;
                }else if(result.x.x == -2)
                    continue;
                q.push(result);
            }
        }
    }
    cout << ans;
}