#include <stdio.h>
#include <deque>

using namespace std;

int N;
deque<int> dq;
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        dq.push_back(i);
    while(!dq.empty()){
        int front = dq.front();
        printf("%d ", front);
        dq.pop_front();
        front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    return 0;
}