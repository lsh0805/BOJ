#include <stdio.h>

const int MAX_N = 100001;
int T, N, M, pos[MAX_N + 1], cnt[4 * 2 * MAX_N + 1], num, top;

int update(int idx, int nodeL, int nodeR, int node, int value){
    if(idx < nodeL || idx > nodeR) return cnt[node];
    if(nodeL == nodeR) return cnt[node] = value;
    int mid = (nodeL + nodeR) / 2;
    return cnt[node] = update(idx, nodeL, mid, node * 2, value) + update(idx, mid + 1, nodeR, node * 2 + 1, value);
}
int query(int left, int right, int nodeL, int nodeR, int node){
    if(right < nodeL || left > nodeR) return 0;
    if(left <= nodeL && right >= nodeR) return cnt[node];
    int mid = (nodeL + nodeR) / 2;
    return query(left, right, nodeL, mid, node * 2) + query(left, right, mid + 1, nodeR, node * 2 + 1);
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        top = N - 1;
        for(int i = 0; i <= 8 * MAX_N; i++)
            cnt[i] = 0;
        for(int i = 0; i <= MAX_N; i++)
            pos[i] = 0;
        for(int i = 0; i < N; i++){
            pos[N - i - 1] = i;
            update(i, 0, 2 * MAX_N, 1, 1);
        }
        for(int i = 0; i < M; i++){
            scanf("%d", &num);
            num--;
            printf("%d ",query(pos[num] + 1, 2 * MAX_N, 0, 2 * MAX_N, 1));
            update(pos[num], 0, 2 * MAX_N, 1, 0);
            pos[num] = ++top;
            update(pos[num], 0, 2 * MAX_N, 1, 1);
        }
        putchar('\n');
    }

    return 0;
}