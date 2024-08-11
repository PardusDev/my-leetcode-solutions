int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Firstly, we need to malloc memory for return variable
    int* result = malloc(2 * sizeof(int));

    // Secondly, we need to write two nested arrays
    // Because for each element we select, we will sum all other elements in the array and check the result.
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int sum = nums[i] + nums[j];
            // Check if the sum of two numbers is equal to the target.
            if (sum == target) {
                // Return index numbers of two number as an array.
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}
