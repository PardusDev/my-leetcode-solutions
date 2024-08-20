/*
	Assignment:	Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

void rotate(int* nums, int numsSize, int k) {
    int* shiftedNums = (int*) malloc(numsSize * sizeof(int));

	// If k is greater than the size of the array, we need to take the modulo of k.
    k = k % numsSize;

    for (int i = 0; i < numsSize; i++) {
		// We need to shift the elements to the right by k steps.
		// We can do this by copying the elements to a new array with the new index.
        shiftedNums[(i + k) % numsSize] = nums[i];
    }

    // Copy the rotated elements back to the original array
    for (int i = 0; i < numsSize; i++) {
        nums[i] = shiftedNums[i];
    }
}