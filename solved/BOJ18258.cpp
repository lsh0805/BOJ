#include <bits/stdc++.h>

using namespace std;

#define fi first;
#define se second;

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, x;
queue<int> q;
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    while(N--){
        cin >> str;
        if(str == "push"){
            cin >> x;
            q.push(x);
        }else if(str == "pop"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }else if(str == "size"){
            cout << q.size() << "\n";
        }else if(str == "empty"){
            cout << q.empty() << "\n";
        }else if(str == "front"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
        }else if(str == "back"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.back() << "\n";
        }
    }
    return 0;
}