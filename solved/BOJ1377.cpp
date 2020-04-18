#include <bits/stdc++.h>

using namespace std;

int N, ans;
pair<int, int> a[500001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++)
        ans = max(ans, a[i].second - i + 1);
    cout << ans;
    return 0;
}