#include <stdio.h>
#include <deque>

using namespace std;

int N, M;

void process(int cnt, deque<int> used){
    if(cnt == M){
        for(int i = 0; i < N; i++){
            while(used.empty() == false){
                printf("%d ", used.front() + 1);
                used.pop_front();
            }
        }
        putchar('\n');
        return;
    }
    for(int i = 0; i < N; i++){
        used.push_back(i);
        process(cnt + 1, used);
        used.pop_back();
    }
}

int main(){
    scanf("%d %d", &N, &M);
    deque<int> used;
    for(int i = 0; i < N; i++){
        used.push_back(i);
        process(1, used);
        used.pop_back();
    }
    return 0;
}