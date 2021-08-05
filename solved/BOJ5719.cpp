#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, M, S, D, u, v, p, d[501];
vector<vector<P>> adj;
priority_queue<P> pq;
vector<queue<P>> previous;

bool dijkstra(bool b){
	previous = vector<queue<P>>(N);
	for(int i = 0; i < N; i++)
		d[i] = INF;
	pq = priority_queue<P>();

	pq.push(P(0, S));
	d[S] = 0;
	while(!pq.empty()){
		P front = pq.top();
		pq.pop();
		int curr = front.second;
		int curr_d = -front.first;
		if(curr == D) return true;
		if(d[curr] < curr_d) continue;
		for(P n : adj[curr]){
			int next = n.second;
			int next_d = n.first;
			if(d[next] > next_d + d[curr]){
				if(b){
					previous[next] = queue<P>();
					previous[next].push(P(curr, next_d));
				}
				pq.push(P(-(next_d + d[curr]), next));
				d[next] = next_d + d[curr];
			}else if(b && d[next] == next_d + d[curr]){
				previous[next].push(P(curr, next_d));
			}
		}
	}
	return false;
}

void remove_edges(int curr){
	while(!previous[curr].empty()){
		P front = previous[curr].front();
		previous[curr].pop();
		int next = front.first;
		int next_d = front.second;
		bool found = false;
		for(int i = 0; i < adj[next].size(); i++){
			if(adj[next][i].first == next_d && adj[next][i].second == curr){
				adj[next].erase(adj[next].begin() + i);
				found = true;
				break;
			}
		}
		if(found) remove_edges(next);
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	while(true){
		cin >> N >> M;
		if(N == 0) break;
		cin >> S >> D;
		adj = vector<vector<P>>(N);
		while(M--){
			cin >> u >> v >> p;
			adj[u].push_back(P(p, v));
		}
		if(!dijkstra(true)){
			cout << "-1\n";
			continue;
		}
		remove_edges(D);
		if(!dijkstra(false)){
			cout << "-1\n";
			continue;
		}
		cout << d[D] << "\n";
	}
	
    return 0;
}