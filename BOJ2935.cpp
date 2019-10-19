#include <iostream>
#include <algorithm>

using namespace std;

string a, b, oper;
int main(){
    cin >> a >> oper >> b;
    if(a.length() < b.length())
        swap(a, b);
    if(oper == "*"){
        for(int i = 0; i < b.size() - 1; i++)
            a += "0";
    }else{
        if(a.length() == b.length())
            a[0] = '2';
        else{
            a[a.length() - b.length()] = '1';
        }
    }
    cout << a;
    return 0;
}