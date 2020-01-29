#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

// 0번 인덱스부터 1번 타자의 정보를 저장, 4번 타자는 무조건 1번 선수 확정이므로 빼 놓음
const int OUT = 0;
vector<int> order{1, 2, 3, 4, 5, 6, 7, 8};
int N, result[9][50], ans;

int simulate(const vector<int> & order){
    int curr = 0, out = 0, state = 0, score = 0;
    for(int inning = 0; inning < N; inning++){
        // 이닝 시작시 상태 초기화
        state = 0;
        out = 0;
        while(out < 3){
            if(curr == 9) curr = 0;
            int hitter = curr > 3 ? order[curr - 1] : order[curr];
            // 4번 타자는 1번 선수
            if(curr == 3)
                hitter = 0;
            // 아웃하면 아웃 수 추가하고 다음 선수 배치
            if(result[hitter][inning] == OUT){
                out++;
                curr++;
                continue;
            }
            // 안타 이상을 쳤을 때는 state에 새로운 선수를 추가하고 선수들을 진루시킴
            state += 1;
            state <<= result[hitter][inning];
            // 한 바퀴 이상 돈 선수들을 빼주면서 점수 카운팅 
            for(int bit = (1 << 4); state >= (1 << 4); bit <<= 1){
                if(state & bit){
                    state -= bit;
                    score++;
                }
            }
            curr++;
        }
    }
    return score;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &result[j][i]);
    do{
        ans = max(ans, simulate(order));
    }while(next_permutation(order.begin(), order.end()));
    printf("%d", ans);
    return 0;
}