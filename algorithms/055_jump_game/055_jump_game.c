/*
	Assignment: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

	Return true if you can reach the last index, or false otherwise.
*/

bool canJump(int* nums, int numsSize) {
    int i, maxIndex;

    i = 0;
    while (i < numsSize) {
        if (i > maxIndex)
            return false;

		// We need to update the maxIndex to the maximum value between the current maxIndex and the sum of the current index and the value of the current index.
        maxIndex = (i + nums[i] > maxIndex) ? i + nums[i] : maxIndex;

        if (maxIndex >= numsSize - 1)
            return true;
            
        i++;
    }
    return false;
}