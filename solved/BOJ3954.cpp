#include <bits/stdc++.h>

using namespace std;

int T, M, C, I, cmd_cnt, brackets[5000], m[100001];
char c[5000], i[5000];
void pairing(){
    stack<int> st;
    for(int i = 0; i < C; i++){
        if(c[i] == '[')
            st.push(i);
        else if(c[i] == ']'){
            int top = st.top();
            st.pop();
            brackets[top] = i;
            brackets[i] = top;
        }
    }
}

void simulate(int ptr_pos, int c_pos, int i_pos){
	int max_ = 0;
    // 종료 체크
    for(int c_pos = 0; c_pos < C; c_pos++){
        switch(c[c_pos]){
            case '+':
                if(++m[ptr_pos] == 256) m[ptr_pos] = 0;
                break;
            case '-':
				if(--m[ptr_pos] < 0) m[ptr_pos] = 255;
                break;
            case '>':
                if(++ptr_pos >= M) ptr_pos = 0;
                break;
            case '<':
                if(--ptr_pos < 0) ptr_pos = M - 1;
                break;
            case '[':
                if(m[ptr_pos] == 0) c_pos = brackets[c_pos];
                break;
            case ']':
                if(m[ptr_pos] != 0){
                    if(cmd_cnt > 5e7)
                    max_ = max(c_pos, max_);
                    c_pos = brackets[c_pos];
                }
                break;
            case '.':
                break;
            case ',':
                if(i_pos >= I) m[ptr_pos] = 255;
                else m[ptr_pos] = (int)i[i_pos++];
                break;
            default:
                break;
        }
           
        if(cmd_cnt > 1e8){
            printf("Loops %d %d\n", brackets[max_], max_);
            return;
        }
		cmd_cnt++;
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
        for(int i = 0; i < M; i++)
            m[i] = 0;
        for(int i = 0; i < C; i++)
            brackets[i] = -1;
        pairing();
        simulate(0, 0, 0);
    }
    return 0;
}