#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

int T, N, arr[100001], num, ans[2], min_ = 2e9;
bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N, cmp);
    for(int i = 0; i < N - 1; i++){
        if(min_ > abs(arr[i] + arr[i + 1])){
            min_ = abs(arr[i] + arr[i + 1]);
            ans[0] = arr[i];
            ans[1] = arr[i + 1];
        }
    }
    if(ans[0] < ans[1])
        cout << ans[0] << " " << ans[1];
    else
        cout << ans[1] << " " << ans[0];
    return 0;
}