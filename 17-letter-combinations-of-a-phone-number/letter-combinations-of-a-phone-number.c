#include <stdlib.h>
#include <string.h>

char **result;
char *mapping[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

int count;
int n;

void backtrack(char *digits, int index, char *current) {

    if (index == n) {
        current[index] = '\0';

        result[count] = malloc((n + 1) * sizeof(char));
        strcpy(result[count], current);

        count++;
        return;
    }

    int digit = digits[index] - '0';
    char *letters = mapping[digit];

    for (int i = 0; letters[i] != '\0'; i++) {

        current[index] = letters[i];

        backtrack(digits, index + 1, current);
    }
}

char** letterCombinations(char* digits, int* returnSize) {

    n = strlen(digits);

    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Maximum combinations for length 4 = 4^4 = 256
    result = malloc(256 * sizeof(char*));

    count = 0;

    char current[5];

    backtrack(digits, 0, current);

    *returnSize = count;

    return result;
}