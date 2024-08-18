void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // First array's last element index
	int i = m - 1;
	// Second array's last element index
    int j = n - 1;
	// Last index of the merged array
    int k = nums1Size - 1; 

	// Merge the two arrays from the end
    while (i >= 0 && j >= 0) {
		// If the first array's element is greater than the second array's element
        if (nums1[i] > nums2[j]) {
			// Copy the first array's element to the merged array
            nums1[k--] = nums1[i--];
        } else {
			// Copy the second array's element to the merged array
            nums1[k--] = nums2[j--];
        }
    }

	// Copy the remaining elements from the second array to the merged array
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}