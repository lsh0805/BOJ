#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

int A, B, C, total;
bool visited[201][201], v[201];


void process(int a, int b, int c){
    visited[a][b] = true;
    if(a == 0)
        v[c] = true;
    //a -> b
    int diff = min(a, B - b);
    if(!visited[a - diff][b + diff])
        process(a - diff, b + diff, c);
    //a -> c
    diff = min(a, C - c);
    if(!visited[a - diff][b])
        process(a - diff, b, c + diff);
    //b -> a
    diff = min(b, A - a);
    if(!visited[a + diff][b - diff])
        process(a + diff, b - diff, c);
    //b -> c
    diff = min(b, C - c);
    if(!visited[a][b - diff])
        process(a, b - diff, c + diff);
    //c -> a
    diff = min(c, A - a);
    if(!visited[a + diff][b])
        process(a + diff, b , c - diff);
    //c -> b
    diff = min(c, B - b);
    if(!visited[a][b + diff])
        process(a, b + diff, c - diff);
}

int main(){
    scanf("%d %d %d", &A, &B, &C);
    process(0, 0, C);
    for(int i = 0; i <= 200; i++){
        if(v[i])
            printf("%d ", i);
    }
    return 0;
}