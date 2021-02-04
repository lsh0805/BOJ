#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, K, pre[100001];
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    memset(pre, -1, sizeof(pre));
    q.push(N);
    pre[N] = N;
    bool flag = false;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            int curr = q.front();
            q.pop();
            if(curr == K){
                flag = true;
                break;
            }
            int nx[3] = {curr - 1, curr + 1, curr * 2};
            for(int j = 0; j < 3; j++){
                if(curr > K  && j == 2) continue;
                if(nx[j] < 0 || nx[j] > 100000 || pre[nx[j]] != -1) continue;
                q.push(nx[j]);
                pre[nx[j]] = curr;
            }
        }
        if(flag) break;
    }
    int pos = K;
    vector<int> ans;
    while(true){
        ans.push_back(pos);
        if(pos == N) break;
        pos = pre[pos];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() - 1<< "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}