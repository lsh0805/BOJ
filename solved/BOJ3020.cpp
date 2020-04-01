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

int T, N, H, ans, num;
vector<int> up, down;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> H;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(i % 2){
            down.push_back(num);
        }else{
            up.push_back(num);
        }
    }
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    int min_ = 2e9, cnt = 0;
    for(int h = 0; h < H; h++){
        int idx = upper_bound(up.begin(), up.end(), h) - up.begin();
        int up_cnt = up.size() - idx;
        idx = upper_bound(down.begin(), down.end(), H - h - 1) - down.begin();
        int down_cnt = down.size()  - idx;
        int total = down_cnt + up_cnt;
        if(min_ > total){
            min_ = total;
            cnt = 1;
        }else if(min_ == total){
            cnt++;
        } 
    }
    cout << min_ << " " << cnt;
    return 0;
}