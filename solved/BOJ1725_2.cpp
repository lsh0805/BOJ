#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> pii;

int N, h[100001], ans;
stack<int> st;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i <= N; i++) {
        if (i < N) cin >> h[i];
        while(!st.empty() && h[st.top()] > h[i]) {
            int top = st.top();
            st.pop();
            if (st.empty()) {
                ans = max(ans, h[top] * i);
            } else {
                ans = max(ans, h[top] * (i - st.top() - 1));
            }        
        }
        st.push(i);
    }
    cout << ans;
    return 0;
}