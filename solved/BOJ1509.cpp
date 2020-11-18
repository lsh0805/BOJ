#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
bool isPalindrome[2501][2501];
int dp[2501];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i = 0; i < str.size(); i++)
        isPalindrome[i][i] = true;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j  + i < str.size(); j++){
            if(i == 0) isPalindrome[j][j] = true;
            else if(i == 1) isPalindrome[j][j + 1] = str[j] == str[j + 1];
            else isPalindrome[j][j + i] = isPalindrome[j + 1][j + i - 1] && str[j] == str[j + i];
        }
    }
    dp[0] = 1;
    for (int i = 1; i < str.size(); i++) {
        if(isPalindrome[0][i]) dp[i] = 1;
        else{
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j < i; j++)
            if(isPalindrome[j][i])dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[str.size() - 1];
}