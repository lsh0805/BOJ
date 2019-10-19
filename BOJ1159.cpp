#include <iostream>

using namespace std;
int N, cnt[26];
bool ans[26], flag;
string str;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--){
        cin >> str;
        if(++cnt[str[0] - 'a'] == 5){
            ans[str[0] - 'a'] = true;
            flag = true;
        }
    }
    for(int i = 0; i < 26; i++)
        if(ans[i]) 
            cout << (char)(i + 'a');
    if(!flag)
        cout << "PREDAJA";
    return 0;
}