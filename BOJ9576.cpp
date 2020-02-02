#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

const int MAX_N = 1001;
int T, N, M, gived[MAX_N], a, b;
vector<P> v;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        v = vector<P>();
        memset(gived, 0, sizeof(gived));
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            --a, --b;
            v.push_back(P(b, a));
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int left = v[i].second, right = v[i].first;
            for(int j = left; j <= right; j++){
                if(!gived[j]){
                    ans++;
                    gived[j] = true;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}