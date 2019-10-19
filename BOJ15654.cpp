#include <stdio.h>
#include <algorithm>

using namespace std; 
int N, M, arr[8], order[8];
bool visited[8];

void process(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            printf("%d ", order[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            order[cnt] = arr[i];
            visited[i] = true;
            process(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            order[0] = arr[i];
            visited[i] = true;
            process(1);
            visited[i] = false;
        }
    }
    return 0;
}