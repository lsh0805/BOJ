#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
long long arr[4 * MAX_N], N, Q, a, b, c, d;

long long sum(int l, int r, int node, int nodeL, int nodeR){
    if(l > nodeR || r < nodeL) return 0;
    if(l <= nodeL && r >= nodeR) return arr[node];
    int mid = (nodeL / 2 + nodeR / 2);
    return  1LL * sum(l, r, node * 2, nodeL, mid) + sum(l, r, node * 2 + 1, mid + 1, nodeR);
}
long long update(int e, int node, int l, int r, int val){
    if(l > e || r < e) return arr[node];
    if(l == r) return arr[node] = val;
    int mid = (l / 2 + r / 2);
    return arr[node] = 1LL * update(e, node * 2, l, mid, val) + update(e, node * 2 + 1, mid + 1, r, val);
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a);
        update(i, 1, 1, N, a);
    }
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a > b)
            swap(a, b);
        printf("%lld\n", sum(a, b, 1, 1, N));
        update(c, 1, 1, N, d);
    }
    return 0;
}