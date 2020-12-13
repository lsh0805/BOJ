#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;
int N, dx[3] = {-1, 0, 1}, queen_pos[16];

bool isValid(int x, int y){
    for(int i = 0; i < y; i++){
        if(queen_pos[i] == x) return false;
        if(abs(queen_pos[i] - x) == abs(i - y)) return false;
    }
    return true;
}

int dfs(int y){
    if(y == N) return 1;
    int ret = 0;
    for(int x = 0; x < N; x++){
        if(isValid(x, y)){
            queen_pos[y] = x;
            ret += dfs(y + 1);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    cout << dfs(0) << "\n";
}