#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, t[10001], indeg[10001], cnt, p, ans, tot[10001];
vector<vector<int>> adj;
queue<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    adj = vector<vector<int>>(N);
    for(int i = 0; i < N; i++){
        cin >> t[i] >> indeg[i];
        tot[i] = t[i];
        ans = max(ans, tot[i]);
        for(int j = 0; j < indeg[i]; j++){
            cin >> p;
            adj[p - 1].push_back(i);
        }
    }
    for(int i = 0; i < N; i++)
        if(indeg[i] == 0)
            q.push(i);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]){
            tot[next] = max(tot[next], tot[curr] + t[next]);
            ans = max(ans, tot[next]);
            if(--indeg[next] == 0)
                q.push(next);
        }
    }
    cout << ans;
}