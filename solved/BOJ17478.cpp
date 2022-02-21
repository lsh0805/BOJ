#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

int N;

void print_underbar(int depth) {
    for (int i = 0; i < depth * 4; i++)
        cout << "_";
}

void recursive(int depth) {
    print_underbar(depth);
    cout << "\"����Լ��� ������?\"" << endl;
    if (depth == N) {
        print_underbar(depth);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
        print_underbar(depth);
        cout << "��� �亯�Ͽ���." << endl;
        return;
    }
    print_underbar(depth);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
    print_underbar(depth);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
    print_underbar(depth);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
    recursive(depth + 1);
    print_underbar(depth);
    cout << "��� �亯�Ͽ���." << endl;
}

int main()
{
    IO;
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
    recursive(0);
    return 0;
}