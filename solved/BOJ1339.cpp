#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, sum[27];
priority_queue<int> pq;
string s[11];
set<char> distinct;
vector<int> v;

int p(int k){
    int ret = 1;
    for(int i = 0; i < k; i++)
        ret *= 10;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
        for(int j = 0; j < s[i].size(); j++){
            if(distinct.count(s[i][j]) == 0)
                distinct.insert(s[i][j]);
        }
    } 
    for(auto it = distinct.begin(); it != distinct.end(); it++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] == *it){
                    int a = s[i][j] - 'A';
                    int pos = s[i].size() - j - 1;
                    sum[a] += p(pos);
                }
            }
        }
        pq.push(sum[*it - 'A']);
    }
    int ans = 0;
    for(int i = 9; !pq.empty(); i--){
        ans += pq.top() * i;
        pq.pop();
    }
    cout << ans;
}