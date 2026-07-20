#include <stdio.h>
#include <string.h>

int main(void) {
    char ch[] = "Hello Would!!!";
    for(int i = 0; i < strlen(ch); i++) {
        for(int j = 0; j <= 26 * 2 + 1; j++) {
            int k = j + 66;
            // printf("%d %d\n", k, ch[i]);
            if (k != int(ch[i])) { 
                printf("%c\n", ch[i]); 
            } else {
                printf("%c", ch[i]);
            }
        }
    }
    getchar();
    getchar();
    return 0;
}
