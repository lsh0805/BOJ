#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

queue<string> q;
string str, ans = "";
int K, level;
bool visited[11][1000001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> str >> K;
    visited[0][stoi(str)] = true;
    q.push(str);
    if(str.length() == 1){
        cout << -1;
        return 0;
    }
    while(!q.empty() && K > level){
        int qsize = q.size();
        level++;
        for(int i = 0; i < qsize; i++){
            string front = q.front();
            q.pop();
            for(int j = 0; j < front.length(); j++){
                for(int k = j + 1; k < front.length(); k++){
                    swap(front[j], front[k]);
                    if(front[0] == '0'){
                        swap(front[j], front[k]);
                        continue;
                    }
                    if(level == K)
                        ans = max(ans, front);
                    if(!visited[level][stoi(front)]){
                        visited[level][stoi(front)] = true;
                        q.push(front);
                    }
                    swap(front[j], front[k]);
                }
            }
        }
    }
    if(ans == ""){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}