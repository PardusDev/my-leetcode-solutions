int romanSignToInt(char current, char nextOne);

int romanToInt(char* s) {
    int i = 0;
    int result = 0;

    // Iterate the string until end.
    while (s[i] != '\0') {
        // Check the next one.
        result += romanSignToInt(s[i], s[i + 1]);

        // Increase index.
        i++;
    }
    return result;
}

int romanSignToInt(char current, char nextOne) {
    switch(current) {
        case 'I':
            if (nextOne == 'V' || nextOne == 'X') {
                return -1;
            } else {
                return 1;
            }
        case 'V':
            return 5;
        case 'X':
            if (nextOne == 'L' || nextOne == 'C') {
                return -10;
            } else {
                return 10;
            }
        case 'L':
            return 50;
        case 'C':
            if (nextOne == 'D' || nextOne == 'M') {
                return -100;
            } else {
                return 100;
            }
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}