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

int T, N, ans;

bool check(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void process(int curr, int cnt){
    if(cnt == N){
        cout << curr << '\n';
        return;
    }
    for(int i = 1; i <= 9; i+=2){
        int next = curr * 10 + i;
        if(check(next))
            process(next, cnt + 1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    int s[4] = {2, 3, 5, 7};
    for(int i = 0; i < 4; i++)
        process(s[i], 1);
    return 0;
}