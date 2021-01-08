#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, M, a[9];

void solve(vector<int> &v, int curr){
    if(v.size() == M){
        for(int i = 0; i < M; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = curr; i < N; i++){
        v.push_back(a[i]);
        solve(v, i);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    vector<int> v = vector<int>();
    for(int i = 0; i < N; i++){
        v.push_back(a[i]);
        solve(v, i);
        v.pop_back();
    }
}