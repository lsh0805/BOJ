#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int N, K, M, V, C;
multiset<int> c;
long long ans;
vector<P> jewel;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &M, &V);
        jewel.push_back(P(V, M));
    }
    for(int i = 0; i < K; i++){
        scanf("%d", &C);
        c.insert(C);
    }
    sort(jewel.begin(), jewel.end());
    reverse(jewel.begin(), jewel.end());
    for(int i = 0; i < N; i++){
        if(c.empty()) break;
        multiset<int>::iterator it = c.lower_bound(jewel[i].second);
        if(it != c.end()){
            ans += jewel[i].first;
            c.erase(it);
        }
    }
    printf("%lld", ans);
    return 0;
}