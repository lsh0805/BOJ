#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, M, K, A[101][101], B[101][101], C[101][101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < K; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int k = 0; k < K; k++){
            for(int j = 0; j < M; j++){
                C[i][k] += A[i][j] * B[j][k];
            }
            cout << C[i][k] << " ";
        }
        cout << "\n";
    }
}