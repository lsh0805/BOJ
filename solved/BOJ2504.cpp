#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

string str;
bool visited[31];
stack<char> st;

ll solve(int curr){
    int ret = 0;
    visited[curr] = true;
    for(int i = curr + 1; i < str.length(); i++){
        if(visited[i]) continue;
        if(str[i] == '(' || str[i] == '[')
            ret += solve(i);
        else{
            visited[i] = true;
            ret = max(ret, 1);
            ret *= str[curr] == '(' ? 2 : 3;
            break;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    bool flag = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '['){
            st.push(str[i]);
        }else if(!st.empty() && ((st.top() == '(' && str[i] == ')') || (st.top() == '[' && str[i] == ']'))){
            st.pop();
        }else{
            flag = true;
            break;
        }
    }
    if(flag || !st.empty())
        cout << 0;
    else{
        int ans = 0;
        for(int i = 0; i < str.length(); i++){
            if(!visited[i])
                ans += solve(i);
        }
        cout << ans;
    }
}