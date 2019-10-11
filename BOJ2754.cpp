#include <iostream>

using namespace std;

int N, num;
float sum, sum2;
string a, b, c;
float getScore(string s){
    float score = 0;
    if(s == "F")
        return score;
    else{
        score = (double)3 - (s[0] - 'A') + 0.7;
        if(s[1] == '+')
            score += 0.6;
        else if(s[1] == '0')
            score += 0.3;
        return score;
    }
}
int main(){
    cin >> N;
    while(N--){
        cin >> a >> num >> c;
        sum += num;
        sum2 += getScore(c) * num;
    }
    printf("%.2f", sum2 / sum);
    return 0;
}