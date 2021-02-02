#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, M;
bool visited[8];
vector<int> v, a;
set<vector<int>> s;

void solve(int curr, int cnt){
    if(cnt == M - 1){
        if(s.count(a) == 0){
            for(int i = 0; i < M; i++)
                cout << a[i] << " ";
            cout << "\n";
            s.insert(a);
        }
        return;
    }

    for(int next = 0; next < N; next++){
        if(visited[next]) continue;
        a[cnt + 1] = v[next];
        visited[next] = true;
        solve(next, cnt + 1);
        visited[next] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    v = vector<int>(N);
    a = vector<int>(M);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int next = 0; next < N; next++){
        if(visited[next]) continue;
        a[0] = v[next];
        visited[next] = true;
        solve(next, 0);
        visited[next] = false;
    }
    return 0;
}