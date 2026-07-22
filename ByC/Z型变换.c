#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows < 2 || len <= numRows) {
        char* res = (char*)malloc((len + 1) * sizeof(char));
        strcpy(res, s);
        return res;
    }

    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowLen = (int*)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int row = 0;
    int dir = 1;
    for (int i = 0; i < len; i++) {
        rows[row][rowLen[row]++] = s[i];
        rows[row][rowLen[row]] = '\0';
        if (row == 0) {
            dir = 1;
        } else if (row == numRows - 1) {
            dir = -1;
        }
        row += dir;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);
    free(rowLen);
    return result;
}