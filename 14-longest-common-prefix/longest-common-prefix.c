#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    // Compare characters of the first string
    for (int i = 0; strs[0][i] != '\0'; i++) {
        
        char current = strs[0][i];

        // Check this character in every other string
        for (int j = 1; j < strsSize; j++) {
            
            if (strs[j][i] == '\0' || strs[j][i] != current) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}