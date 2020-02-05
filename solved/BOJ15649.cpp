#include <stdio.h>
#include <deque>

using namespace std;

int N, M;

void solve(deque<int> q, int used){
    if(q.size() == M){
        for(int i = 0; i < M; i++){
            printf("%d ", q.front() + 1);
            q.pop_front();
        }
                putchar('\n');
        return;
    }
    for(int i = 0; i < N; i++){
        if((used & (1 << i)) == 0){
            q.push_back(i);
            solve(q, used | (1 << i));
            q.pop_back();
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    deque<int> q;
    for(int i = 0; i < N; i++){
        q.push_back(i);
        solve(q, 1 << i);
        q.pop_back();
    }
    return 0;
}