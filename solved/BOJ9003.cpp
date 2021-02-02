#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N;
string str, temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    getline(cin, temp);
    for(int i = 0; i < N; i++){
        getline(cin, str);
        temp = "";
        for(int i = 0; i < str.length(); i++){
            if(str[i] != ' ')
                temp += str[i];
            if(str[i] == ' ' || i == str.length() - 1){
                reverse(temp.begin(), temp.end());
                cout << temp << " ";
                temp = "";
            }
            
        }
        cout << '\n';
    }
    return 0;
}