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

int T, N, ans;
queue<p> q;
bool visited[1001][1001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    visited[1][0] = true;
    q.push(p(1, 0));
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            p front = q.front();
            q.pop();
            int curr = front.first;
            int copy_sz = front.second;
            if(curr == N){
                cout << ans;
                return 0;
            }
            if(curr + copy_sz <= 1000 && copy_sz > 0 && !visited[curr + copy_sz][copy_sz]){
                q.push(p(curr + copy_sz, copy_sz));
                visited[curr + copy_sz][copy_sz] = true;
            }
            if(!visited[curr][curr]){
                q.push(p(curr, curr));
                visited[curr][curr] = true;
            }
            if(curr - 1 >= 0 && !visited[curr - 1][copy_sz]){
                q.push(p(curr - 1, copy_sz));
                visited[curr - 1][copy_sz] = true;
            }
        }
        ans++;
    }
    return 0;
}