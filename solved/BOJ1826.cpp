#include <bits/stdc++.h>

using namespace std;

int N, a, b, L, P, ans;

typedef pair<int, int> p;
vector<p> v;
priority_queue<int> pq;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back(p(a, b));
    }
    cin >> L >> P;

    sort(v.begin(), v.end());
    int r = 0;
    while(P < L && r < N){
        for(; r < N && v[r].first <= P; r++)
            pq.push(v[r].second);
        if(pq.size() == 0) break;
        P += pq.top();
        pq.pop();
        ans++;
    }
    if(P >= L)
        cout << ans;
    else
        cout << "-1";
    return 0;
}