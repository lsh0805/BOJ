#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, M, a, b, c, s, e, opt[10001];
vector<vector<P>> adj;
priority_queue<P> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    adj = vector<vector<P>>(N + 1);
    for(int i = 0; i < M; i++){
      cin >> a >> b >> c;
      adj[a].push_back(P(c, b));
      adj[b].push_back(P(c, a));
    }
    cin >> s >> e;
    opt[s] = INF;
    pq.push(P(INF, s));
    while(!pq.empty()){
      P top = pq.top();
      int curr = top.se;
      int w = top.fi;
      pq.pop();
      if(opt[curr] > w) continue;
      for(P next_p : adj[curr]){
        int next = next_p.se;
        int next_w = min(w, next_p.fi);
        if(next_w > opt[next]){
          opt[next] = next_w;
          pq.push(P(next_w, next));
        }
      }
    }
    cout << opt[e];
    return 0;
}