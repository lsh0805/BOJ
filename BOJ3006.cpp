#include <stdio.h>

const int MAX_N = 100001;
int N, arr[4 * MAX_N], num, order[MAX_N];

int query(int l, int r, int nodeL, int nodeR, int node){
    if(l > nodeR || r < nodeL) return 0;
    if(l <= nodeL && r >= nodeR) return arr[node];
    int mid = (nodeL + nodeR) / 2;
    return query(l, r, nodeL, mid, node * 2) + query(l, r, mid + 1, nodeR, node * 2 + 1);
}

int update(int idx, int nodeL, int nodeR, int node, int value){
    if(nodeL > idx || nodeR < idx) return arr[node];
    if(nodeL == nodeR) return arr[node] = value;
    int mid = (nodeL + nodeR) / 2;
    return arr[node] = (update(idx, nodeL, mid, node * 2, value) + update(idx, mid + 1, nodeR, node * 2 + 1, value));
}


int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &num);
        order[num] = i;
        update(i, 1, N, 1, 1);
    }
    int mid = N / 2 + N % 2;
    for(int i = 1; i <= N; i++){
        int front = i, end = N - i + 1;
        if(front > mid) break;
        printf("%d\n", query(1, order[front] - 1, 1, N, 1));
        update(order[front], 1, N, 1, 0);
        if(end == mid) break;
        printf("%d\n", query(order[end] + 1, N, 1, N, 1));
        update(order[end], 1, N, 1, 0);
    }
    return 0;
}