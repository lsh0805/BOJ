#include <stdio.h>

int num, ans, x, y;

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            scanf("%d", &num);
            if (ans <= num) {
                ans = num;
                x = j + 1;
                y = i + 1;
            }
        }
    printf("%d\n%d %d", ans, y, x);
    return 0;
}