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

int T, N, M, K, ans = 2e9, A[51][51], temp[51][51], r[7], c[7], s[7];

void rotate(int r, int c, int s){
    for(int k = 0; k < N / 2; k++){
        int temp = A[r - s + k][c - s + k];
        for(int i = c - s + k + 1; i <= c + s - k; i++){
            int temp2 = A[r - s + k][i];
            A[r - s + k][i] = temp;
            temp = temp2;
        }
        for(int j = r - s + k + 1; j <= r + s - k; j++){
            int temp2 = A[j][c + s - k];
            A[j][c + s - k] = temp;
            temp = temp2;
        }
        for(int i = c + s - k - 1; i >= c - s + k; i--){
            int temp2 = A[r + s - k][i];
            A[r + s - k][i] = temp;
            temp = temp2;
        }
        for(int j = r + s - k - 1; j >= r - s + k; j--){
            int temp2 = A[j][c - s + k];; 
            A[j][c - s + k] = temp;
            temp = temp2;
        }
    }
}
int check(){
    int ret = 2e9;
    for(int i = 0; i < N; i++){
        int line = 0;
        for(int j = 0; j < M; j++){
            line += A[i][j];
        }
        ret = min(ret, line);
    }
    return ret;
}

void init(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            A[i][j] = temp[i][j];
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
            temp[i][j] = A[i][j];
        }
    for(int i = 0; i < K; i++)
        cin >> r[i] >> c[i] >> s[i];
    vector<int> v(K);
    iota(v.begin(), v.end(), 0);
    do{
        init();
        for(int i = 0; i < K; i++)
            rotate(r[v[i]] - 1, c[v[i]] - 1, s[v[i]]);
        ans = min(ans, check());
    }while(next_permutation(v.begin(), v.end()));
    cout << ans;
    return 0;
}