#include <stdio.h>
#include <stack>

using namespace std;

stack<int> st;
char c;
int main(){
    while((c = getchar()) != '\n'){
        if(c == ')'){
            while(st.top() != '('){
                putchar(st.top());
                st.pop();
            }
            st.pop();
        }else if(c >= 'A' && c <= 'Z'){
            putchar(c);
        }else if(c == '('){
            st.push(c);
        }else if(c == '*' || c == '/' || c == '+' || c == '-'){
            while(!st.empty() && ((c == '+' || c == '-') || (st.top() == '*' || st.top() == '/')) && st.top() != '('){
                putchar(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        putchar(st.top());
        st.pop();
    }
    return 0;
}