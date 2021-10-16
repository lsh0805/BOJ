#include <bits/stdc++.h>>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> P;

int N, M, d[1001], u, v, w, s, e, pr[1001];
vector<vector<P>> adj;
priority_queue<P> pq;
stack<int> st;

int main(){
    cin >> N >> M;
    for(int i = 0; i <= N; i++)
        d[i] = 2e9;
    adj = vector<vector<P>>(N + 1);
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back(P(v, w));
    }
    cin >> s >> e;
    d[s] = 0;
    pr[s] = -1;
    pq.push(P(s, 0));
    while(!pq.empty()){
        P front = pq.top();
        pq.pop();
        int curr = front.fi;
        int curr_d = -front.se;
        if(curr_d > d[curr]) continue;
        for(P next_p : adj[curr]){
            int next = next_p.fi;
            int next_c = next_p.se;
            if(curr_d + next_c < d[next]){
                d[next] = curr_d + next_c;
                pq.push(P(next, -(next_c + curr_d)));
                pr[next] = curr;
            }
        }
    }
    int curr = e;
    st.push(curr);
    while(true){
        if(pr[curr] == -1) break;
        st.push(pr[curr]);
        curr = pr[curr];
    }
    cout << d[e] << "\n";
    cout << st.size() << "\n";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}