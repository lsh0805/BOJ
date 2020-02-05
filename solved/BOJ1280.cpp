#include <stdio.h>

const long long MAX_X = 200000, MOD = 1e9 + 7;
int N;
long long sum[4 * MAX_X], ans = 1, cnt[4 * MAX_X], x;

struct CountSegment{
    long long update(int idx, int nodeL, int nodeR, int node, int value){
        if(idx < nodeL || idx > nodeR) return cnt[node];
        if(idx == nodeL && idx == nodeR) return cnt[node] += value;
        int mid = (nodeL + nodeR) / 2;
        return cnt[node] = update(idx, nodeL, mid, node * 2, value) + update(idx, mid + 1, nodeR, node * 2 + 1, value);
    }
    long long query(int left, int right, int nodeL, int nodeR, int node){
        if(left > nodeR || right < nodeL) return 0;
        if(left <= nodeL && right >= nodeR) return cnt[node];
        int mid = (nodeL + nodeR) / 2;
        return query(left, right, nodeL, mid, 2 * node) + query(left, right, mid + 1, nodeR, 2 * node + 1);
    }
};

struct DistSumSegment{
    long long update(int idx, int nodeL, int nodeR, int node, long long value){
        if(idx < nodeL || idx > nodeR) return sum[node];
        if(idx == nodeL && idx == nodeR) return sum[node] += value;
        int mid = (nodeL + nodeR) / 2;
        return sum[node] = update(idx, nodeL, mid, node * 2, value) + update(idx, mid + 1, nodeR, node * 2 + 1, value);
    }
    long long query(int left, int right, int nodeL, int nodeR, int node){
        if(left > nodeR || right < nodeL) return 0;
        if(left <= nodeL && right >= nodeR) return sum[node];
        int mid = (nodeL + nodeR) / 2;
        return query(left, right, nodeL, mid, 2 * node) + query(left, right, mid + 1, nodeR, 2 * node + 1);
    }
};

int main(){
    scanf("%d", &N);
    CountSegment cnt_seg;
    DistSumSegment dist_seg;
    for(int i = 0; i < N; i++){
        scanf("%lld", &x);
        cnt_seg.update(x, 0, MAX_X, 1, 1);
        dist_seg.update(x, 0, MAX_X, 1, x);
        if(i >= 1){
            long long front = cnt_seg.query(0, x - 1, 0, MAX_X, 1) * x - dist_seg.query(0, x-1, 0, MAX_X, 1);
            long long back = dist_seg.query(x + 1, MAX_X, 0, MAX_X, 1) - cnt_seg.query(x + 1, MAX_X, 0, MAX_X, 1) * x;
            ans *= (front % MOD + back % MOD) % MOD;
            ans %= MOD;
        }
    }
    printf("%lld", ans % MOD);
    return 0;
}