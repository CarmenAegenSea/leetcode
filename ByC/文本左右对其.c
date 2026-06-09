#include <stdio.h>
#include <stdlib.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int last = 0;
    
    char text = (char*)calloc(maxWidth, ' ');
    int length = 0;
    int next = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (length <= maxWidth) {
            length += strlen(words[i]);
        } else {
            
        }
    }
}