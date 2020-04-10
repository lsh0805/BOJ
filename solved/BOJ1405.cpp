#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

const int INIT = 20;
int T, N, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
double p[4], ans;
bool visited[40][40];

double solve(int curr, int x, int y){
    if(curr == N)
        return 1;
    double ret = 0;
    for(int i = 0; i < 4; i++){
        int _x = x + dx[i], _y = y + dy[i];
        if(visited[_x][_y])
            continue;
        visited[_x][_y] = true;
        ret += solve(curr + 1, _x, _y) * p[i];
        visited[_x][_y] = false;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < 4; i++){
        cin >> p[i];
        p[i] /= 100;
    }
    visited[INIT][INIT] = true;
    for(int i = 0; i < 4; i++){
        int _x = INIT + dx[i], _y = INIT + dy[i];
        visited[_x][_y] = true;
        ans += solve(1, _x, _y) * p[i];
        visited[_x][_y] = false;
    }
    printf("%.9lf", ans);
    return 0;
}