#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N, ans;
string expression;

int calculate(int a, char oper, int b){
    switch (oper)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
    default:
        return a*b;
    }
    return 0;
}

int solve(int curr, int sum){
    int next = expression[curr + 1] - '0';
    if(curr >= expression.length())
        return sum;
    if(curr == expression.length() - 2)
        return calculate(sum, expression[curr], next);
    if(curr <= expression.length() - 4)
        return max(solve(curr + 2, calculate(sum,expression[curr],next)), solve(curr + 4, calculate(sum, expression[curr], (calculate(next, expression[curr + 2], expression[curr + 3] - '0')))));
    return solve(curr + 2, sum + next);
}

int main(){
    cin >> N >> expression;
    cout << solve(1, expression[0] - '0') << '\n';
    return 0;
}