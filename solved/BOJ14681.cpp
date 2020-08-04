#include <iostream>

using namespace std;

int a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(a > 0 && b > 0){
        cout << "1";
    }else if(a < 0 && b > 0){
        cout << "2";
    }else if(a < 0 && b < 0){
        cout << "3";
    }else if(a > 0 && b < 0){
        cout << "4";
    }
    return 0;
}