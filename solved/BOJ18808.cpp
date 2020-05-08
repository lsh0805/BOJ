#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, M, K, m[41][41], r[101], c[101], ans;
vector<vi> sticker[101];

int check(int x, int y, int idx){
    int ret = 0;
    for(int i = 0; i < r[idx]; i++){
        for(int j = 0; j < c[idx]; j++){
            int x_ = x + j, y_ = y + i;
            if(sticker[idx][i][j] && m[y_][x_]) return 0;
            ret += sticker[idx][i][j];
        }
    }
    return ret;
}

void put(int x, int y, int idx){
    for(int i = 0; i < r[idx]; i++){
        for(int j = 0; j < c[idx]; j++){
            int x_ = x + j, y_ = y + i;
            m[y_][x_] |= sticker[idx][i][j];
        }
    }
}

void rotate(int idx){
    vector<vi> temp = vector<vi>(c[idx], vi(r[idx]));
    for(int i = 0; i < r[idx]; i++){
        for(int j = 0; j < c[idx]; j++){
            int y = j, x = r[idx] - 1 - i;
            temp[y][x] = sticker[idx][i][j];
        }
    }
    sticker[idx] = temp;
    // 가로 세로 크기 변경
    swap(r[idx], c[idx]);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        cin >> r[i] >> c[i];
        sticker[i] = vector<vi>(r[i], vi(c[i]));
        for(int j = 0; j < r[i]; j++){
            for(int k = 0; k < c[i]; k++){
                cin >> sticker[i][j][k];
            }
        }
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < 4; j++){
            // 붙였는지 여부
            bool flag = false;
            for(int y = 0; y < N; y++){
                for(int x = 0; x < M; x++){
                    if(N <= y + r[i] - 1 || M <= x + c[i] - 1) continue;
                    int cnt = check(x, y, i);
                    if(!cnt) continue;
                    ans += cnt;
                    flag = true;
                    put(x, y, i);
                    break;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
            if(j != 3)
                rotate(i);
        }
    }
    cout << ans;
    return 0;
}