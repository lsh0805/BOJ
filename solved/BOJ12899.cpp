#include <stdio.h>

using namespace std;

const int MAX_N = 2000001;
int N, t, x, cnt;
int arr[4 * MAX_N];

int update(int left, int right, int idx, int node, int value){
    if(left > idx || right < idx) return arr[node];
    if(left == right) return arr[node] += value;
    int mid = (left + right) / 2;
    return arr[node] = update(left, mid, idx, node * 2, value) + update(mid + 1, right, idx, node * 2 + 1, value);
}

int query(int node, int left, int right, int k){
    if(left == right) return left;
    int pivot = arr[node * 2], mid = (left + right) / 2;
    if(pivot >= k) return query(node * 2, left, mid, k);
    else return query(node * 2 + 1, mid + 1, right, k - pivot); 
}

int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &t, &x);
        if(t == 1){
            update(1, MAX_N, x, 1, 1);
        }else{
            int num = query(1, 1, MAX_N, x);
            printf("%d\n", num);
            update(1, MAX_N, num, 1, -1);
        }
    }
    return 0;
}