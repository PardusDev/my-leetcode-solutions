int convertToReverse(int x);

bool isPalindrome(int x) {
    // Check the number is 0?
    if (x < 0) return false;

    return convertToReverse(x) == x;
}

int convertToReverse(int x) {
    int digitNumber = 0;
    int temp = x;
    int result = 0;

    // We need to get digit number.
    while (temp >= 10) {
        temp /= 10;
        digitNumber++;
    }

    // We start reversing with this loop.
    while(digitNumber > 0) {
        result += (x % 10) * pow(10, digitNumber);
        x /= 10;
        digitNumber--;
    }
    result += x;
    return result;
}
