#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6;
long long arr[4 * MAX_N + 1];
int N, M, a, b, c;

long long update(int left, int right, int node, int idx, int value){
    if(left > idx || right < idx) return arr[node];
    if(left == right)
        return arr[node] = value;
    int mid = (left + right) / 2;
    return arr[node] = update(left, mid, 2 * node, idx, value) + update(mid + 1, right, 2 * node + 1, idx, value);
}

long long query(int left, int right, int nLeft, int nRight, int node){
    if(left > nRight || right < nLeft) return 0;
    if(left <= nLeft && right >= nRight) return arr[node];
    int mid = (nLeft + nRight) / 2;
    return query(left, right, nLeft, mid, node * 2) + query(left, right, mid + 1, nRight, node * 2 + 1);
}

int main(){
    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            if(b > c)
                swap(b, c);
            printf("%lld\n", query(b, c, 1, N, 1));
        }else{
            update(1, N, 1, b, c);
        }
    }
    return 0;
}