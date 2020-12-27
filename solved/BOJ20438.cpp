#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, K, Q, M, num, sum[5010], s, e;
bool sleep[5010];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> Q >> M;
    for(int i = 0; i < K; i++){
        cin >> num;
        sleep[num] = true;
    }
    for(int i = 0; i < Q; i++){
        cin >> num;
        if(sleep[num]) continue;
        for(int j = num; j <= N + 2; j+=num){
            if(sleep[j]) continue;
            sum[j] = 1;
        }
    }
    for(int i = 3; i <= N + 2; i++)
        sum[i] = sum[i - 1] + sum[i];
    while(M--){
        cin >> s >> e;
        cout << (e - s + 1) - (sum[e] - sum[s - 1]) << "\n";
    }
}