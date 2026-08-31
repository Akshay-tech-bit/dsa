int romanToInt(char* s) {
    int value[256] = {0};

    value['I'] = 1;
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;

    int result = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (i + 1 < n && value[(unsigned char)s[i]] < value[(unsigned char)s[i + 1]]) {
            result -= value[(unsigned char)s[i]];
        } else {
            result += value[(unsigned char)s[i]];
        }
    }

    return result;
}