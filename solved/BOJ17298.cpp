#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, num, ans[1000001];
priority_queue<P> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < N; i++){
      cin >> num;
      while(!pq.empty() && -pq.top().fi < num){
        ans[pq.top().se] = num;
        pq.pop();
      }
      pq.push(P(-num, i));
    }
    for(int i = 0; i < N; i++)
      cout << ans[i] << " ";
    return 0;
}