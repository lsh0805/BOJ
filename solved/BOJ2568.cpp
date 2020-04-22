#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

const int MAX_V = 500001;
int N, a, b, arr[MAX_V];
bool used[MAX_V];
pair<int, int> tracking[500001];
vector<int> v;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        arr[a] = b;
    }
    for(int i = 1; i < MAX_V; i++){
        if(arr[i] == 0) continue;
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if(it == v.end()){
            v.push_back(arr[i]);
            tracking[i] = mp(v.size(), i);
        }else{
            *it = arr[i];
            tracking[i] = mp(it - v.begin() + 1, i);
        }
    }
    int size = v.size();
    cout << N - v.size() << "\n";
    for(int i = MAX_V - 1; i > 0; i--){
        if(tracking[i].first == size){
            size--;
            used[tracking[i].second] = true;
        }
    }
    for(int i = 1; i < MAX_V; i++){
        if(arr[i] != 0 && used[i] == false)
            cout << i << "\n";
    }
    return 0;
}