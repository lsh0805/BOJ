#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

int T, N, K, ans = 2e9, level;
bool visited[100001][18];

queue<p> q;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    q.push(p(N, 0));
    visited[N][0] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            p front = q.front();
            int curr = front.first, teleport = front.second;
            q.pop();
            if(curr == K && ans > level - teleport)
                ans = level - teleport;
            if(curr > 0 && !visited[curr - 1][teleport]){
                visited[curr - 1][teleport] = true;
                q.push(p(curr - 1, teleport));
            }
            if(curr < 100000 && !visited[curr + 1][teleport]){
                visited[curr + 1][teleport] = true;
                q.push(p(curr + 1, teleport));
            }
            if(curr <= 50000 && !visited[curr * 2][teleport + 1]){
                visited[curr * 2][teleport + 1] = true;
                q.push(p(curr * 2, teleport + 1));
            }
        }
        level++;
    }
    cout << ans;
    return 0;
}