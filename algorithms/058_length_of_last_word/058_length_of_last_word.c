/*
	Assignment: Given a string s consisting of words and spaces, return the length of the last word in the string.

	A word is a maximal substring consisting of non-space characters only.
*/

bool isChar(char n) {
    if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
        return true;
    else
        return false;
}

bool isWhiteSpace(char n) {
    if (n == ' ' || n == '\t' || n== '\n' || n == '\v' || n == '\f' || n == '\r')
        return true;
    else
        return false;
}

int lengthOfLastWord(char* s) {
    int i, wordLength;

    i = 0;
    wordLength = 0;
    while (s[i] != '\0')
        i++;

    i--;
    while (i >= 0 && isWhiteSpace(s[i]))
        i--;

    while (i >= 0 && isChar(s[i])) {
        wordLength++;
        i--;
    }

    return wordLength;
}