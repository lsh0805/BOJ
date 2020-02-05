#include <stdio.h>
#include <stack>

using namespace std;

int T, M, C, I, before_ptr_pos[5000], cmd_cnt, brackets[5000];
unsigned char c[5000], i[5000], m[100001], before_val[5000];
bool met_input[5000], met_output[5000];

void pairing(){
    stack<int> st;
    for(int i = 0; i < C; i++){
        if(c[i] == '[')
            st.push(i);
        else if(c[i] == ']' && !st.empty()){
            int top = st.top();
            st.pop();
            brackets[top] = i;
            brackets[i] = top;
        }
    }
}

void simulate(stack<int>& st, int ptr_pos, int c_pos, int i_pos){
    // 종료 체크
    while(!(cmd_cnt >= 50000000 || c_pos < 0 || c_pos >= C || i_pos < 0 || i_pos >= I + 1)){
        cmd_cnt++;
        switch(c[c_pos]){
            case '+':
                m[ptr_pos]++;
                c_pos++;
                break;
            case '-':
                m[ptr_pos]--;
                printf("m: %d\n", m[ptr_pos]);
                c_pos++;
                break;
            case '>':
                ptr_pos++;
                c_pos++;
                break;
            case '<':
                ptr_pos--;
                c_pos++;
                break;
            case '[':
                // 만약 닫는 괄호 짝이 없으면 종료
                if(brackets[c_pos] == -1){
                    printf("Terminates\n");
                    return;
                }
                st.push(c_pos);
                // 현재 포인터가 가르키는 값이 0이라면 닫는 괄호로 점프
                if(m[ptr_pos] == 0)
                    c_pos = brackets[c_pos];
                // 0이 아니라면 현재의 값을 저장한 후 반복문내의 명령어 실행
                else{
                    before_val[c_pos] = m[ptr_pos];
                    before_ptr_pos[c_pos] = ptr_pos;
                    c_pos++;
                }
                break;
            case ']':
            {
                // 만약 위에 여는 괄호 짝이 없으면 종료
                if(st.empty()){
                    printf("Terminates\n");
                    return;
                }
                int top = st.top();
                st.pop();
                // 현재 포인터가 가르키는 값이 0이라면 계속 진행
                if(m[ptr_pos] == 0){
                    c_pos++;
                }else{
                    // 입력받는 명령이 하나라도 존재하거나 반복 전 포인터 위치와 값이 같지않다면 무한 루프가 생길 일은 없다(무한루프 이전에 에러 발생)
                    if(!met_input[top] && ((!met_output[top] && before_ptr_pos[top] == ptr_pos && before_val[top] == m[ptr_pos]) || (met_output[top] && before_ptr_pos[top] != ptr_pos))){
                        printf("Loops %d %d\n", top, c_pos);
                        return;
                    // 루프가 아닐 경우 여는 괄호로 점프
                    }else
                        c_pos = top;
                }
                break;
            }
            case '.':
                // 만약 현재 반복문 괄호가 하나라도 있다면(반복문이 진행 중) 출략 명령어 발견 체크
                if(!st.empty())
                    met_output[st.top()] = true;
                // 포인터가 범위를 벗어난 경우 종료
                if(ptr_pos < 0 || ptr_pos >= M){
                    printf("Terminates\n");
                    return;
                }
                c_pos++;
                break;
            case ',':
                // 만약 현재 반복문 괄호가 하나라도 있다면(반복문이 진행 중) 입력 명령어 발견 체크
                if(!st.empty())
                    met_input[st.top()] = true;
                if(i_pos == I)
                    m[ptr_pos] = 255;
                else
                    m[ptr_pos] = i[i_pos];
                c_pos++;
                i_pos++;
                break;
            default:
                break;
        }
    }
    printf("Terminates\n");
    return;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %s %s", &M, &C, &I, &c, &i);
        // 값 초기화
        cmd_cnt = 0;
        for(int i = 0; i < C; i++){
            brackets[i] = -1;
            met_input[i] = false;
            met_output[i] = false;
            before_ptr_pos[i] = -1;
            before_val[i] = 0;
        }
        pairing();
        stack<int> st = stack<int>();
        simulate(st, 0, 0, 0);
    }
    return 0;
}