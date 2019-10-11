#include <stdio.h>

using namespace std;

const int MAX_N = 1e5;
int N, K, arr[4 * MAX_N];

int update(int left, int right, int idx, int node, int val){
    if(left > idx || right < idx) return arr[node];
    if(left == right) return arr[node] = val;
    int mid = (left + right) / 2;
    return arr[node] = update(left, mid, idx, node * 2, val) + update(mid + 1, right, idx, node * 2 + 1, val);
}

int kth(int left, int right, int node, int k){
    if(left == right) return left;
    int pivot = arr[node * 2];
    int mid = (left + right) / 2;
    if(pivot >= k) return kth(left, mid, node * 2, k);
    else return kth(mid + 1, right, node * 2 + 1, k - pivot);
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        update(1, N, i, 1, 1);
    int curr_k = K;
    printf("<");
    for(int i = 0; i < N; i++){
        int num = kth(1, N, 1, curr_k);
        update(1, N, num, 1, 0);
        printf("%d", num);
        if(i != N - 1){
            printf(", ");
            curr_k = (curr_k + K - 1);
            if(curr_k % (N - i - 1) == 0)
                curr_k = (N - i - 1);
            else
                curr_k %= (N - i - 1);
        }
    }
    printf(">");
    return 0;
}