#include <stdio.h>

const int MAX_N = 1e5 + 1;
int N, K, x, a, b, arr[4 * MAX_N];
char c;
int update(int left, int right, int idx, int node, int value){
    if(left > idx || right < idx) return arr[node];
    if(left == right) return arr[node] = value;
    int mid = (left + right) / 2;
    int a = update(left, mid, idx, node * 2, value), b = update(mid + 1, right, idx, 2 * node + 1, value);
    if(a == -1 || b == -1)
        return arr[node] = -1;
    return arr[node] = a + b;
}

int query(int left, int right, int nodeL, int nodeR, int node){
    if(left > nodeR || right < nodeL) return 0;
    if(left <= nodeL && nodeR <= right)
        return arr[node];
    int mid = (nodeL + nodeR) / 2;
    int a = query(left, right, nodeL, mid, node * 2), b = query(left, right, mid + 1, nodeR, 2 * node + 1);
    if(a == -1 || b == -1)
        return -1;
    return a + b;
}
int convert(int num){
    if(num == 0)
        num = -1;
    else if(num > 0)
        num = 0;
    else
        num = 1;
    return num;
}
int main(){
    while(scanf("%d %d", &N, &K) != EOF){
        for(int i = 0; i < N; i++){
            scanf("%d", &x);
            update(0, N - 1, i, 1, convert(x));
        }
        while(K--){
            getchar();
            scanf("%c %d %d", &c, &a, &b);
            if(c == 'C'){
                update(0, N - 1, a - 1, 1, convert(b));
            }else if(c == 'P'){
                int q = query(a - 1, b - 1, 0, N - 1, 1);
                if(q == -1)
                    printf("0");
                else if(q % 2 == 0)
                    printf("+");
                else
                    printf("-");
            }
        }
        putchar('\n');
    }
    return 0;
}