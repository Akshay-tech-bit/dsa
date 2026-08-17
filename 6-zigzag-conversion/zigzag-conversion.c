#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // If only one row or string is too short
    if (numRows == 1 || numRows >= len) {
        return s;
    }

    // Allocate memory for result
    char* result = (char*)malloc((len + 1) * sizeof(char));

    int index = 0;

    // Process each row
    for (int row = 0; row < numRows; row++) {

        int step1 = 2 * (numRows - row - 1);
        int step2 = 2 * row;

        int pos = row;

        while (pos < len) {
            result[index++] = s[pos];

            // For first and last row, only one step is needed
            if (row != 0 && row != numRows - 1) {

                int diagonal = pos + step1;

                if (diagonal < len) {
                    result[index++] = s[diagonal];
                }
            }

            pos += 2 * (numRows - 1);
        }
    }

    result[index] = '\0';

    return result;
}