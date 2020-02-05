#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        vector<string> v;
        string str;
        bool flag = false;
        for(int i = 0; i < N; i++){
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size() - 1; i++){
            auto res = std::mismatch(v[i].begin(), v[i].end(), v[i + 1].begin());
            if(res.first == v[i].end()){
                printf("NO\n");
                flag = true;
                break; 
            }
        }
        if(!flag)
            printf("YES\n");
    }
    return 0;
}