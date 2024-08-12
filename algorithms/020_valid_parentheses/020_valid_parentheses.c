bool isValid(char* s) {
    int length = strlen(s);
    char* stack = (char*) malloc(length * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < length; i++) {
        char currentChar = s[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            // Add openers to stack structure.
			stack[++top] = currentChar;
        } else {
			// If the stack is empty, return false.
			// This means that there is no opener for the current closer.
            if (top == -1) {
				// don't forget to free the memory.
                free(stack);
                return false;
            }
			// If the stack is not empty, check the last opener.
            char lastOpen = stack[top--];
			// If the last opener is not the same type with the current closer, return false.
            if ((currentChar == ')' && lastOpen != '(') ||
                (currentChar == '}' && lastOpen != '{') ||
                (currentChar == ']' && lastOpen != '[')) {
                free(stack);
                return false;
            }
        }
    }

	// If the stack is empty, return true.
    bool result = (top == -1);
	// don't forget to free the memory.
    free(stack);
    return result;
}