#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, pair<int, int>>> P;
int N, M, idx, a, b, c, order;
P arr[1001];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &idx, &a, &b, &c);
        arr[i] = P(-a, {-b, {-c, idx }});
    }
    sort(arr, arr + N);
    int p1 = 1, p2 = 1, p3 = 1;
    for(int i = 0; i < N; i++){
        int c1 = arr[i].first, c2 = arr[i].second.first, c3 = arr[i].second.second.first;
        if(c1 != p1 || c2 != p2 || c3 != p3)
            order = i + 1;
        p1 = c1;
        p2 = c2;
        p3 = c3;
        if(arr[i].second.second.second == M){
            printf("%d", order);
        }
    }
    return 0;
}