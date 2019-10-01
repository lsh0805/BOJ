#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> P;

const int MAX_N = 100001;
int T, N, M, a, b, c, val[MAX_N];
P arr[4 * MAX_N];

P update(int idx, int nodeL, int nodeR, int node, int value){
    if(idx > nodeR || idx < nodeL) return arr[node];
    if(nodeL == nodeR){ 
        val[idx] = value;
        return arr[node] = P(value, value);
    }
    int mid = (nodeL + nodeR) /2;
    P u = update(idx, nodeL, mid, node * 2, value);
    P v = update(idx, mid + 1, nodeR, node * 2 + 1, value);
    return arr[node] = P(min(u.first, v.first), max(u.second, v.second));
}
P query(int left, int right, int nodeL, int nodeR, int node){
    if(left > nodeR || right < nodeL) return P(MAX_N, -1);
    if(left <= nodeL && right >= nodeR) return arr[node];
    int mid = (nodeL + nodeR) /2;
    P u = query(left, right, nodeL, mid, node * 2);
    P v = query(left, right, mid + 1, nodeR, node * 2 + 1);
    return P(min(u.first, v.first), max(u.second, v.second));
}


int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < 4 * MAX_N; i++)
            arr[i] = P(MAX_N, -1);
        for(int i = 0; i < N; i++)
            update(i, 0, N - 1, 1, i);
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &a, &b, &c);
            if(a == 1){
                P q = query(b, c, 0, N - 1, 1);
                printf(q.second == c && q.first == b ? "YES\n" : "NO\n");
            }else{
                int cpy = val[b];
                update(b, 0, N - 1, 1, val[c]);
                update(c, 0, N - 1, 1, cpy);
            }
        }
    }
    return 0;
}