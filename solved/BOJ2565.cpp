#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> P;
int N, a, b, cnt;
vector<P> v;
int arr[30000];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        v.push_back(P(a, b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(arr[cnt] < v[i].second){
            cnt++;
            arr[cnt] = v[i].second;
        }else{
            auto it = lower_bound(arr, arr + cnt, v[i].second);
            *it = v[i].second;
        }
    }
    printf("%d", N - cnt);
    return 0;
}