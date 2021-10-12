#include <bits/stdc++.h>

using namespace std;

#define first x
#define second y

typedef pair<int, int> P;

int N, a[31], M, b[8];
bool dp[2][70001];

void getSum(int s, int e, int idx, int curr, int sum){
    if(s >= N) return;
    if(curr == e - s + 1){
        dp[idx][sum + 15000] = true;
        return;
    }
    getSum(s, e, idx, curr + 1, sum + a[s + curr]);
    getSum(s, e, idx, curr + 1, sum);
    getSum(s, e, idx, curr + 1, sum - a[s + curr]);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    cin >> M;
    for(int i = 0; i < M; i++)
        cin >> b[i];
    int mid = N / 2;
    getSum(0, mid, 0, 0, 0);
    getSum(mid + 1, N - 1, 1, 0, 0);
    for(int i = 0; i < M; i++){
        bool flag = false;
        for(int j = -15000; j < b[i]; j++){
            int diff = abs(b[i] - j);
            if(dp[0][b[i] + 15000] || dp[1][b[i] + 15000] || (dp[0][j + 15000] && dp[1][diff + 15000])){
                cout << "Y ";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "N ";
    }
    return 0;
}