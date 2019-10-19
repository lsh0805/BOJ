#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N, cnt;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--){
    stack<char> st;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(st.empty() || st.top() != s[i])
                st.push(s[i]);
            else
            {
                st.pop();
            }
        }
    
        cnt += st.empty();
    }
    printf("%d", cnt);
    return 0;
}