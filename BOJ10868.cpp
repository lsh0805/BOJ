#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 100001, INF = 1e9 + 1;
int N, M, arr[4 * MAX_N], num, a, b;

int update(int idx, int nodeL, int nodeR, int node, int value){
    if(idx < nodeL || idx > nodeR) return arr[node];
    if(nodeL == nodeR) return arr[node] = value;
    int mid = (nodeL + nodeR) / 2;
    return arr[node] = min(update(idx, nodeL, mid, node *2, value), update(idx, mid + 1, nodeR, node * 2 + 1, value));
}

int query(int left, int right, int nodeL, int nodeR, int node){
    if(left > nodeR || right < nodeL) return INF;
    if(left <= nodeL && right >= nodeR) return arr[node];
    int mid = (nodeL + nodeR) / 2;
    return min(query(left, right, nodeL, mid, node * 2), query(left, right, mid + 1, nodeR, node * 2 + 1));
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 4 * MAX_N; i++)
        arr[i] = INF;
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        update(i, 0, N - 1, 1, num);
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a - 1, b - 1, 0, N - 1, 1));
    }
    return 0;
}