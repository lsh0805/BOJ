#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, num, ans;
priority_queue<int> p_pq, n_pq;
bool zero = false;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while(N--){
        cin >> num;
        if (num > 0) {
            p_pq.push(num);
        } else if(num == 0){
            zero = true;
        } else {
            n_pq.push(-num);
        }
    }
    while(!p_pq.empty()){
        if(p_pq.size() >= 2){
            int x = p_pq.top();
            p_pq.pop();
            int y = p_pq.top();
            p_pq.pop();
            if(y == 1)
                ans += x + y;
            else
                ans += x * y;
        }else{
            ans += p_pq.top();
            p_pq.pop();
        }
    }
    while(!n_pq.empty()){
            int x = n_pq.top();
            n_pq.pop();
            int y = n_pq.top();
            n_pq.pop();
            ans += x * y;
        }else{
            ans += (-n_pq.top()) * !zero;
            n_pq.pop();
        }
    }
    cout << ans;
    return 0;
}