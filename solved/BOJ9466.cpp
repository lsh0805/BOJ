#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

typedef long long ll;

int visited[100001], finished[100001], N, S[100001], ans, T;
stack<int> st;

void dfs(int curr){
    visited[curr] = true;
    st.push(curr);
    if(visited[S[curr]] == false)
        dfs(S[curr]);
    else if(finished[S[curr]] == false)
        while(true){
            int front = st.top();
            st.pop();
            ans--;
            if(front == S[curr])
                break;
        }
    finished[curr] = true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        ans = N;
        st = stack<int>();
        memset(finished, 0, sizeof(finished));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < N; i++){
            cin >> S[i];
            S[i]--;
        }
        for(int i = 0; i < N; i++)
            dfs(i);
        cout << ans << "\n";
    }
}