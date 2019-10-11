#include <map>
#include <iostream>
#include <string>

using namespace std;
map<string, int> m;
string arr[100005], str;
int N, M;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        m[arr[i]] = i;
    }
    for(int i = 0; i < M; i++){
        cin >> str;
        if(str[0] >= 'A' && str[0] <= 'Z'){
            cout << m[str] << '\n';
        }else{
            cout << arr[stoi(str)] << '\n';
        }
    }
    return 0;
}