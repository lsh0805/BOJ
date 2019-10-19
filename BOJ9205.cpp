#include <stdio.h>
#include <utility>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;

typedef pair<int , int> P;

int T, N, x, y;
P arr[103];
bool visited[103];

int getDistance(int a, int b){
    return abs(arr[a].first - arr[b].first) + abs(arr[a].second - arr[b].second);
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(visited, false, sizeof(visited));
        queue<int> q;
        scanf("%d", &N);
        N += 2;
        for(int i = 0; i < N; i++){
            scanf("%d %d", &x, &y);
            arr[i] = {x, y};
        }
        q.push(0);
        visited[0] = true;
        bool check = false;
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0 ; i < qsize; i++){
                int curr = q.front();
                q.pop();
                if(curr == N - 1){
                    check = true;
                    break;
                }
                for(int next = 0; next < N; next++){
                    if(visited[next] || getDistance(curr, next) > 1000) continue;
                    q.push(next);
                    visited[next] = true;
                }
            }
            if(check)
                break;
        }
        if(check)
            printf("happy\n");
        else
            printf("sad\n");
    }
    return 0;
}