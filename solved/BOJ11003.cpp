#include <iostream>
#include <deque>

using namespace std;

const int INF = 2e9;
int N, L, num;
deque<pair<int, int>> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(dq.empty()){
            dq.push_back({num, i});
            cout << num << " ";
            continue;
        }
        if(dq.front().second < i - L + 1)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > num)
            dq.pop_back();
        dq.push_back({num, i});
        cout << dq.front().first << " ";
    }
    return 0;
}