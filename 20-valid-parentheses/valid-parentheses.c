#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[10004];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {

        // Opening brackets ko stack mein push karo
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }

        // Closing brackets
        else {
            // Agar stack empty hai
            if (top == -1) {
                return false;
            }

            char open = stack[top--];

            // Matching bracket check karo
            if ((s[i] == ')' && open != '(') ||
                (s[i] == '}' && open != '{') ||
                (s[i] == ']' && open != '[')) {
                return false;
            }
        }
    }

    // Stack empty hona chahiye
    return top == -1;
}