#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, num, a[1000001], cnt[1000001], ans[1000001];
stack<pair<int, int>> st;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = N - 1; i >= 0; i--){
        while(!st.empty() && st.top().fi <= cnt[a[i]])
            st.pop();
        ans[i] = (!st.empty() && st.top().fi > cnt[a[i]]) ? st.top().se : -1;
        st.push(mp(cnt[a[i]], a[i]));
    }
    for(int i = 0; i < N; i++)
        cout << ans[i] << " ";
    return 0;
}