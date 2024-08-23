/*
	Assignment: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

	The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

	You must write an algorithm that runs in O(n) time and without using the division operation.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int *) malloc(numsSize * sizeof(int));
    int leftProduct, rightProduct;


    leftProduct = 1;
    rightProduct = 1;
    // The loop for left production:
    for(int i = 0; i < numsSize; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }

    // The loop for right production
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}