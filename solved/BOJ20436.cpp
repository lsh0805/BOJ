#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

map<char, P> m_l, m_r;
P curr_l, curr_r;
char c_l, c_r;
string str;
int ans = 0;

int getDistance(P p1, P p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c_l >> c_r;
    m_l['q'] = P(0, 0);
    m_l['w'] = P(1, 0);
    m_l['e'] = P(2, 0);
    m_l['r'] = P(3, 0);
    m_l['t'] = P(4, 0);
    m_r['y'] = P(5, 0);
    m_r['u'] = P(6, 0);
    m_r['i'] = P(7, 0);
    m_r['o'] = P(8, 0);
    m_r['p'] = P(9, 0);
    m_l['a'] = P(0, 1);
    m_l['s'] = P(1, 1);
    m_l['d'] = P(2, 1);
    m_l['f'] = P(3, 1);
    m_l['g'] = P(4, 1);
    m_r['h'] = P(5, 1);
    m_r['j'] = P(6, 1);
    m_r['k'] = P(7, 1);
    m_r['l'] = P(8, 1);
    m_l['z'] = P(0, 2);
    m_l['x'] = P(1, 2);
    m_l['c'] = P(2, 2);
    m_l['v'] = P(3, 2);
    m_r['b'] = P(4, 2);
    m_r['n'] = P(5, 2);
    m_r['m'] = P(6, 2);
    curr_l = m_l[c_l];
    curr_r = m_r[c_r];
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(m_l.find(str[i]) != m_l.end()){
            ans += getDistance(m_l[str[i]], curr_l);
            curr_l = m_l[str[i]];
        }else{
            ans += getDistance(m_r[str[i]], curr_r);
            curr_r = m_r[str[i]];
        }
        ans++;
    }
    cout << ans << "\n";
}