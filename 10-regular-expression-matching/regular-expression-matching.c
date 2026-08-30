#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[21][21] = {false};

    // Empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns like a*, a*b*, a*b*c*
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // Normal character or '.'
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            // '*'
            else if (p[j - 1] == '*') {

                // '*' matches zero occurrences
                dp[i][j] = dp[i][j - 2];

                // '*' matches one or more occurrences
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}