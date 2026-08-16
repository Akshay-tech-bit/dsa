int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];

    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        if (lastIndex[(unsigned char)s[right]] >= left) {
            left = lastIndex[(unsigned char)s[right]] + 1;
        }

        lastIndex[(unsigned char)s[right]] = right;

        int currentLength = right - left + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}