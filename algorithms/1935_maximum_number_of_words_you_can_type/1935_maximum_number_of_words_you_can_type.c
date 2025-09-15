#include <stdio.h>

int canBeTypedWords(char* text, char* brokenLetters) {
    // Lets build broken sets
    unsigned char broken[26] = {0};
    for (char *p = brokenLetters; *p; ++p) {
        broken[(unsigned)(*p - 'a')] = 1;
    }

	// Now count words that can be typed
    int count = 0;

	// Current word is typeable so far
    int ok = 1;

	// Iterate through each character in the text
    for (char *p = text;; ++p) {
        char ch = *p;

        if (ch == ' ' || ch == '\0') {
            // End of a word
            if (ok) count++;
            if (ch == '\0') break; 
            ok = 1;               
        } else {
            // Check if the character is broken
            if (broken[(unsigned)(ch - 'a')]) ok = 0;
        }
    }
    return count;
}