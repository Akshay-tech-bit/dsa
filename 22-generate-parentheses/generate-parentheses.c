#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **result, char *current, int pos,
               int open, int close, int n, int *returnSize) {

    if (pos == 2 * n) {
        current[pos] = '\0';

        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Add opening parenthesis
    if (open < n) {
        current[pos] = '(';

        backtrack(result, current, pos + 1,
                  open + 1, close, n, returnSize);
    }

    // Add closing parenthesis
    if (close < open) {
        current[pos] = ')';

        backtrack(result, current, pos + 1,
                  open, close + 1, n, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {

    *returnSize = 0;

    char **result = malloc(1430 * sizeof(char*));
    char *current = malloc((2 * n + 1) * sizeof(char));

    backtrack(result, current, 0, 0, 0, n, returnSize);

    free(current);

    return result;
}
