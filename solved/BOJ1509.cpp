#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> pii;

string str;
bool isPalindrome[2501][2501];
int dp[2501];

int solve(int curr) {
    if (curr == str.length()) return 0;
    int & ret = dp[curr];
    if (ret != 0) return ret;
    ret = 2e9;
    for (int next = curr + 1; next <= str.length(); next++) {
        if (isPalindrome[curr][next - 1])
        ret = min(ret, solve(next) + 1);
    }
    return ret;
}

int main()
{
    IO;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; i + j < str.length(); j++) {
            if (str[j] == str[j + i]) {
                if (i == 0 || i == 1) {
                    isPalindrome[j][i + j] = true;
                } else{
                    isPalindrome[j][i + j] = isPalindrome[j + 1][i + j - 1];
                } 
            }
        }
    }
    cout << solve(0);

    return 0;
}