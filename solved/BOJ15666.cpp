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

int N, M, seq[9];
vector<int> v;
void solve(int num, int idx, int cnt){
	bool checked[10001] = {false, };
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = idx; i < N; i++){
        if(v[i] >= v[idx] && !checked[v[i]]){
            seq[cnt] = v[i];
			checked[v[i]] = true;
            solve(v[i], i, cnt + 1);
        }
    }
}
int main(){
    IO;
    cin >> N >> M;
    v = vector<int>(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
	bool checked[10001] = {false, };
    for(int i = 0; i < N; i++){
		if(!checked[v[i]]){
        	seq[0] = v[i];
			checked[v[i]] = true;
        	solve(v[i], i, 1);
		}
    }
    return 0;
}