#include <stdio.h>
#include <stdlib.h>

int cnt[26];

int main() {
    FILE *fp;
    char c;
    char* filename = "infile.txt";
    fp = fopen(filename, "r");
    while ((c = getc(fp)) != EOF){
      if(c >= 'a' && c <= 'z')
        cnt[c - 'a']++;
    }
    fclose(fp);
    for(int i = 1; i <= 26; i++){
      printf("%c: %5d ", i + 'a' - 1, cnt[i - 1]);
      if(i % 6 == 0)
        putchar('\n');
    }
    return 0;
}