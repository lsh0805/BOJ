#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M, num, ans, a;
vector<set<int>> v;


int findMin(){
    int ret = -1;
    int value = 100000;
    for(int i = 0; i < N; i++){
        if(v[i].size() > 0 && value > v[i].size()){
            value = v[i].size();
            ret = i;
        }
    }
    return ret;
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        set<int> s;
        for(int j = 0; j < num; j++){
            scanf("%d", &a);
            s.insert(a);
        }
        v.push_back(s);
    }
    while(true){
        int idx = findMin();
        if(idx == -1) break;
        int value = *v[idx].begin();
        v[idx].clear(); 
        for(int i = 0; i < N; i++)
            v[i].erase(value);
        ans++;
    }
    printf("%d", ans);
    return 0;
}