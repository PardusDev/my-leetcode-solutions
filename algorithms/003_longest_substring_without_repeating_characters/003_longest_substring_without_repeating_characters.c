#include <string.h>

int lengthOfLongestSubstring(char* s) {
    if (!s) return 0;

	// last seen index of each character, -1 if not seen
    int last[256];
    for (int i = 0; i < 256; ++i) last[i] = -1;

	// length of the best substring found
    int best = 0;

	// start index of current substring without repeating characters
    int start = 0;

	// Iterate through the string
    for (int i = 0; s[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)s[i];

        // If this char was seen inside the current window, move start past it
        if (last[c] >= start) start = last[c] + 1;

		// Update last seen index of this character
        last[c] = i;

		// Update best length if needed
        int len = i - start + 1;
        if (len > best) best = len;
    }
    return best;
}