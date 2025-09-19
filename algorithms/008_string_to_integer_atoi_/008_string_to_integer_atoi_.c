int myAtoi(char* s) {
	if (!s) return 0;

	int i = 0;

	// Skip leading whitespace
	while (s[i] == ' ') i++;

	// Handle optional sign
	int sign = 1;
	if (s[i] == '+' || s[i] == '-') {
		if (s[i] == '-') sign = -1;
		i++;
	}

	// Convert digits to integer
	long long res = 0;
	
	int hasDigits = 0;

	const long long POS_LIMIT = INT_MAX; //  2147483647
	const long long NEG_LIMIT = -(long long)INT_MIN; //  2147483648

    while (s[i] >= '0' && s[i] <= '9') {
		int d = s[i] - '0';
		hasDigits = 1;

		// Check for overflow/underflow before multiplying and adding
		if (sign == 1) {
			if (res > POS_LIMIT / 10 || (res == POS_LIMIT / 10 && d > POS_LIMIT % 10)) {
				return INT_MAX;
			}
		} else {
			if (res > NEG_LIMIT / 10 || (res == NEG_LIMIT / 10 && d > NEG_LIMIT % 10)) {
				return INT_MIN;
			}
		}

		res = res * 10 + d;
		i++;
	}

	if (!hasDigits) return 0;

	long long finalRes = sign * res;
	if (finalRes > INT_MAX) return INT_MAX;
	if (finalRes < INT_MIN) return INT_MIN;
	return (int)finalRes;
}