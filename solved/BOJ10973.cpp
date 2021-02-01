#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N;
vector<int> v, temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    v = vector<int>(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    temp = v;
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    prev_permutation(v.begin(), v.end());
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(temp[i] != v[i]){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i = 0; i < N; i++)
            cout << v[i] << " ";
    }else{
        cout << -1;
    }
    return 0;
}