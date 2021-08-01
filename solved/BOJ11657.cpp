#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> P;
vector<vector<P>> adj;
int N, M, a, b, c;
long long upper[501];
const int INF = 1e9, MAX_DIST = 7e7;
int main() {
	scanf("%d %d", &N, &M);
	adj = vector<vector<P>>(N);
	for (int i = 0; i < N; i++)
		upper[i] = INF;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		adj[a].push_back(P(c, b));
	}
	upper[0] = 0;
	bool updated = false;
	for (int i = 0; i < N; i++) {
		for (int here = 0; here < N; here++) {
			for (P next_pair : adj[here]) {
				int cost = next_pair.first;
				int next = next_pair.second;
				if (upper[here] != INF && upper[next] > upper[here] + cost) {
					upper[next] = upper[here] + cost;
					if(i == N-1) updated = true;
				}
			}
		}
		if (updated)
			break;
	}
	if (updated) {
		printf("-1");
		return 0;
	}
	for(int i = 1; i < N - 1; i++)
		if (upper[i] == INF) {
			printf("-1\n");
		}
		else {
			printf("%d\n", upper[i]);
		}
	if (upper[N - 1] == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", upper[N - 1]);
	}
	return 0;
}