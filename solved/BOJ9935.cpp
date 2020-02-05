#include <iostream>
#include <stack>
#include <utility>

using namespace std;

typedef pair<char, int> P;
stack<P> st;
string str, key, ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str >> key;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(!st.empty())
            cnt = st.top().second;
        else
            cnt = 0;
        if(str[i] == key[cnt]){
            st.push({str[i], cnt + 1});
            if(cnt + 1 == key.size())
                for(int i = 0; i < cnt + 1; i++)
                    st.pop();
        }else{
            st.push({str[i], str[i] == key[0]});
        }
    }
    while(!st.empty()){
        ans += st.top().first;
        st.pop();
    }
    if(ans.size() == 0){
        cout << "FRULA";
        return 0;
    }
    for(int i = ans.size() - 1; i >= 0; i --){
        cout << ans[i];
    }
    
    return 0;
}