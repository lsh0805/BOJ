#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, M, parent[200001], r[200001], a, b, c, sum, max_;
priority_queue<P2> pq;

int get_parent(int u){
	if(parent[u] == u) return u;
	return parent[u] = get_parent(parent[u]);
}

bool merge(int u, int v){
	if(r[u] < r[v]) swap(u, v);
	u = get_parent(u);
	v = get_parent(v);
	if(u == v) return false;
	if(r[u] == r[v]) r[u]++;
	parent[v] = u;
	return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		parent[i] = i;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		pq.push(P2(-c, P(a - 1, b - 1)));
	}
	while(!pq.empty())
	{
		P2 e = pq.top();
		pq.pop();
		int w = -e.fi, u = e.se.fi, v = e.se.se;
		if(merge(u, v))
		{
			max_ = w;
			sum += w;
		}
	}
	cout << sum - max_;
    return 0;
}