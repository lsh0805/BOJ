#include <iostream>

using namespace std;

string str;
int a, b;
int main(){
    cin >> str;
    for(int i = 0; i < str.size() - 2; i++){
        if(str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I')
            a++;
        else if(str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
            b++;
    }
    printf("%d\n%d", a, b);
    return 0;
}