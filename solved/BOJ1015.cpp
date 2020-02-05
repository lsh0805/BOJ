#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;
int N, a[51], cnt[1001], c;
deque<int> order[1001];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", a + i);
        cnt[a[i]]++;
    }
    for(int i = 1; i <= 1000; i++)
        while(cnt[i] > 0){
            cnt[i]--;
            order[i].push_back(c++);
        }
    for(int i = 0; i < N; i++){
        printf("%d ", order[a[i]].front());
        order[a[i]].pop_front();
    }
    return 0;
}