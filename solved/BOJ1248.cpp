#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, p_sum[11];
char c;
vector<vector<char>> v;

bool check(char c, int num){
    if(c == '0')
        return num == 0;
    else if(c == '+')
        return num > 0;
    else
        return num < 0;
}

bool solve(int curr){
    for(int i = 0; i <= curr; i++){
        if(!check(v[i][curr - i], p_sum[curr] - (i > 0 ? p_sum[i - 1] : 0))){
            return false;
        }
    }
    if(curr == N - 1)
        return true;
    for(int next = -10; next <= 10; next++){
        p_sum[curr + 1] = p_sum[curr] + next;
        if(solve(curr + 1))
            return true;
        p_sum[curr + 1] = 0;
    }
    return false;
}

int main(){
    cin >> N;
    v = vector<vector<char>>(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i; j++){
            cin >> c;
            v[i].push_back(c);
        }
    }
    for(int next = -10; next <= 10; next++){
        p_sum[0] = next;
        if(solve(0)){
            cout << p_sum[0] << " ";
            for(int i = 1; i < N; i++)
                cout << p_sum[i] - p_sum[i - 1] << " ";
            return 0;
        }
        p_sum[0] = 0;
    }
    return 0;
}