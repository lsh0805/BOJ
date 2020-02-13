#include <bits/stdc++.h>

using namespace std;

int N, arr[101][30], a_cnt, b_cnt, ans;
string str;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < str.size(); j++)
            arr[i][str[j] - 'A']++;
        if(i == 0) continue;
        for(int j = 0; j < 26; j++){
            if(arr[0][j] > arr[i][j])
                a_cnt += arr[0][j] - arr[i][j];
            if(arr[0][j] < arr[i][j])
                b_cnt += arr[i][j] - arr[0][j];
        }
        if(a_cnt <= 1 && b_cnt <= 1)
            ans++;
        a_cnt = 0;
        b_cnt = 0;
    }
    cout << ans << '\n';
    return 0;
}