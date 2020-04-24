#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int T, K, num;
char Q;
map<int, int> m;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        m = map<int, int>();
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> Q >> num;
            if(Q == 'I')
                m[num]++;
            else{
                if(m.size() == 0) continue;
                if(num == -1){
                    auto p = *m.begin();
                    if(--m[p.first] == 0)
                        m.erase(p.first);
                }else{
                    auto p = *m.rbegin();
                    if(--m[p.first] == 0)
                        m.erase(p.first);
                }
            }
        }
        if(m.size() == 0)
            cout << "EMPTY\n";
        else
            cout << (*m.rbegin()).fi <<  " " << (*m.begin()).fi << "\n";
    }
    return 0;
}