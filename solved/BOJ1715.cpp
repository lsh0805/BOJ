#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
int N, ans, num;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        pq.push(-num);
    }
    while(pq.size() >= 2){
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();
        ans += first + second;
        pq.push(-(first + second));
    }
    printf("%d", ans);
    return 0;
}