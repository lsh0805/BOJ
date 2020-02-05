#include <stdio.h>
#include <vector>

using namespace std;

int N, Q, a, b, c;

struct Unionfind{
    vector<int> parent, rank;
    Unionfind(int n): parent(n), rank(n){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v)
            return;
        if(rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        rank[v] += rank[u] == rank[v];
    }
    void remove(int u){
        parent[u] = u;
    }
};

int main(){
    scanf("%d %d", &N, &Q);
    Unionfind unionfind = Unionfind(N);
    
    for(int i = 1; i < N; i++){
        int parent;
        scanf("%d", &parent);
        unionfind.merge(parent - 1, i);
    }
    for(int i = 0; i < N - 1 + Q; i++){
        scanf("%d", &a);
        if(a == 0){
            scanf("%d", &b);
            unionfind.remove(b - 1);
        }else{
            scanf("%d %d", &b, &c);
            if(unionfind.find(b - 1) == unionfind.find(c - 1)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}