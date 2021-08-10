#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

pair<int, int> tracking[1000001];
int N, arr[1000001], ans, num;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		arr[i] = -2e9;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (arr[ans] < num) {
			ans++;
			arr[ans] = num;
			tracking[i] = { ans, num };
		}
		else {
			int *it = lower_bound(arr + 1, arr + ans + 1, num);
			*it = num;
			tracking[i] = { it - arr, num };
		}
	}
	printf("%d\n", ans);
	stack<int> LIS;
	for (int i = N - 1; i >= 0; i--) {
		if (ans == tracking[i].first) {
			ans--;
			LIS.push(tracking[i].second);
		}
	}
	while (!LIS.empty()) {
		printf("%d ", LIS.top());
		LIS.pop();
	}
	return 0;
}