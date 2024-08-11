char* longestCommonPrefix(char** strs, int strsSize) {
    // Set the prefix as the first string.
    char* prefix = strs[0];
    int prefixLength = 0;
    int j = 0;

    // Calculate the length of selected prefix
    while (prefix[prefixLength] != '\0') {
        prefixLength++;
    }

    for (int i = 1; i < strsSize; i++) {
        j = 0;
        char* str = strs[i];
        
        // Iterate selected string and search shorter common prefix
        while (str[j] != '\0' && j < prefixLength &&  strs[i][j] == prefix[j]) {
            j++;
        }

        prefixLength = j;
    }

    prefix[prefixLength] = '\0';
    return prefix;
}
