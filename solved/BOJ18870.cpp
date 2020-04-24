#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, x[1000001];
set<int> s;
map<int, int> m;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        s.insert(x[i]);
    }
    int cnt = 0;
    for(auto it = s.begin(); it != s.end(); it++, cnt++)
        m[*it] = cnt;
    for(int i = 0; i < N; i++)
        cout << m[x[i]] << " ";
    return 0;
}