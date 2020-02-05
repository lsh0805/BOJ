#include <bits/stdc++.h>

using namespace std;

int N;
set<string> s;
string str1, str2;
int main(){
    cin >> N;
    while(N--){
        cin >> str1 >> str2;
        if(str2 == "enter")
            s.insert(str1);
        else
            s.erase(str1);
    }
    vector<string> v(s.begin(), s.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return 0;
}