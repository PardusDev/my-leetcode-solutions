/*
	Assignment: Given an array nums of size n, return the majority element.

	The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

// We will solve this problem by using Boyer-Moore Voting Algorithm.
int majorityElement(int* nums, int numsSize) {
    int majorityNumber;
    int majorityCount;

    majorityNumber = -1;
    majorityCount = 0;
    for(int i = 0; i < numsSize; i++) {
        if(majorityCount == 0) {
            majorityNumber = nums[i];
            majorityCount = 1;
        } else {
            if (nums[i] == majorityNumber)
                majorityCount++;
            else
                majorityCount--;
        }
    }
    return majorityNumber;
}