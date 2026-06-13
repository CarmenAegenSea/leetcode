#include <stdio.h>
#include <stdlib.h>

int* makeNums(const int** caiyao, int D,int  )
int main() {
    int numsSize;
    scanf("%d", &numsSize);
    int caiyaoSize;
    int length;
    scanf("%d %d", &caiyaoSize, &length);
    int* caiyao = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        caiyao = (int*)malloc(sizeof(int) * 2);
       scanf("%d %d", &caiyao[i][0], &caiyao[i][1]);
    }
    
    return 0;
}