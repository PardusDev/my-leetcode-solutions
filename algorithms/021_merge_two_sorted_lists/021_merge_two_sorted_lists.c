#include <stdlib.h>

struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node
	struct ListNode dummy;
	dummy.next = NULL;

	// A pointer to track the end of the merged list
	struct ListNode* tail = &dummy;

	// Loop until either list1 or list2 is exhausted
	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			tail->next = list1;
			list1 = list1->next;
		} else {
			tail->next = list2;
			list2 = list2->next;
		}
		// Move the tail pointer forward
		tail = tail->next;
	}

	// If there are remaining nodes in either list, append them
	if (list1 != NULL) {
		tail->next = list1;
	} else if (list2 != NULL) {
		tail->next = list2;
	}

	// Return the next of dummy node which is the head of the merged list
	return dummy.next;
}