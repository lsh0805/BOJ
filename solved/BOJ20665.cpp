#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<pair<int, int>, int> P1;
typedef pair<pair<int,int>, pair<int, int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, T, M, s, e;
bool isUsing[101];
string x, y;
priority_queue<P1> s_pq;
priority_queue<P> e_pq;
vector<P> t;

int to_time(string str){
    string hour = str.substr(0, 2);
    string minute = str.substr(2, 2);
    hour = hour[0] == '0' ? str.substr(1, 1) : hour;
    int time = stoi(hour) * 60 + stoi(minute);
    return time;
}

int find_farthest(){
    int ret = 0, max_ = 0;
    for(int i = 0; i < N; i++){
        if(isUsing[i]) continue;
        int min_ = N + 1;
        for(int l = i - 1; l >= 0; l--){
            if(isUsing[l]){
                min_ = min(min_, i - l);
                break;
            }
        }
        for(int r = i + 1; r < N; r++){
            if(isUsing[r]){
                min_ = min(min_, r - i);
                break;
            }
        }
        if(min_ == N + 1) return 0;
        if(max_ < min_){
            
            ret = i;
            max_ = min_;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T >> M;
    M--;
    for(int i = 0; i < T; i++){
        cin >> x >> y;
        s = to_time(x), e = to_time(y);
        t.push_back(P(s, e));
        s_pq.push(P1(P(-s, -(e - s)), i));
    }
    int last_time = 540;
    int ans = 0;
    while(!s_pq.empty()){
        P1 curr = s_pq.top();
        s_pq.pop();
        int st = -curr.first.first;
        int diff = -curr.first.second;
        int idx = curr.second;
        while(!e_pq.empty() && -e_pq.top().first <= st){
            P user = e_pq.top();
            e_pq.pop();
            int ed = -user.first;
            int seat = user.second;
            isUsing[seat] = false;
        }
        int k = find_farthest();
        if(k == M){
            ans += st - last_time;
            last_time = t[idx].second;
        }
        isUsing[k] = true;
        e_pq.push(P(-t[idx].second, k));
    }
    
    cout << ans + (1260 - last_time) << "\n";
    return 0;
}