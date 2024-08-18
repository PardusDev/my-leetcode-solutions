/*
	Assignment: 
	Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
	The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

	Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
	Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
	The remaining elements of nums are not important as well as the size of nums.

	Return k.
*/

int removeElement(int* nums, int numsSize, int val) {
	int result;
    int k;

    k = numsSize - 1;
	result = numsSize;
	for(int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
			// If the element is equal to val, we need to remove it.
			// We can do this by copying the last element to the current element.
			// Then we need to decrease the result variable.
            for (;k > 0; k--) {
                if (nums[k] != val) {
                    nums[i] = nums[k];
                    k--;
                    break;
                }
            }
			result--;
		}
    }
	return result;
}