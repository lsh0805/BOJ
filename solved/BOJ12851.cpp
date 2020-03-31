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

int T, N, K, cnt, level;
p visited[100001];

queue<int> q;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    q.push(N);
    visited[N] = p(1, 1);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curr = q.front();
            q.pop();
            if(curr == K){
                cout << level << '\n' << visited[curr].se;
                return 0;
            }
            p & minus = visited[curr - 1], & plus = visited[curr + 1], & multi = visited[curr * 2];
            if(curr > 0 && (minus.fi == 0 || minus.fi == level + 1)){
                if(minus.fi != level + 1) q.push(curr - 1);
                minus = p(level + 1, minus.se + visited[curr].se);
            }
            if(curr < 100000 && (plus.fi == 0 || plus.fi == level + 1)){
                if(plus.fi != level + 1) q.push(curr + 1);
                plus = p(level + 1, plus.se + visited[curr].se);
            }
            if(curr <= 50000 && (multi.fi == 0 || multi.fi == level + 1)){
                if(multi.fi != level + 1) q.push(curr * 2);
                multi = p(level + 1, curr == 1 ? multi.se + 1 : multi.se + visited[curr].se);
            }
        }
        level++;
    }
    return 0;
}