#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
typedef pair<int, int> ii;

string str, temp, ans;
bool flag;

int main()
{
    IO;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '<')
        {
            flag = true;
            if (temp.length())
            {
                reverse(temp.begin(), temp.end());
                ans += temp;
                temp.clear();
            }
            temp.push_back(str[i]);
        }
        else if (str[i] == '>')
        {
            flag = false;
            temp.push_back(str[i]);
            ans += temp;
            temp.clear();
        }
        else if (str[i] == ' ' && !flag)
        {
            reverse(temp.begin(), temp.end());
            ans += temp + " ";
            temp.clear();
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    if (temp.length())
    {
        reverse(temp.begin(), temp.end());
        ans += temp;
        temp.clear();
    }
    cout << ans << endl;
    return 0;
}