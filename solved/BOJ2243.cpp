#include <stdio.h>

const int MAX_N = 1000001;
int N, sum[4 * MAX_N], a, b, c, start_leaf = 1048576;

void update(int node, int cnt){
    while(node != 0){
        sum[node] += cnt;
        node /= 2;    
    }
}
int find(int k, int node){
    if(node >= start_leaf) return node - start_leaf + 1;
    int next = sum[node * 2];
    return (k > next) ? find(k - next, node * 2 + 1) : find(k, node * 2);
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a);
        if(a == 1){
            scanf("%d", &b);
            int sugar = find(b, 1);
            update(sugar + start_leaf - 1, -1);
            printf("%d\n", sugar);
        }else{
            scanf("%d %d", &b, &c);
            update(b + start_leaf - 1, c);
        }
    }
    return 0;
}