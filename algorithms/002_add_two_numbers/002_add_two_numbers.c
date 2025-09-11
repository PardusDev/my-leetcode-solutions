#include <stdlib.h>

// Definition for singly-linked list. Its given in the problem statement.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Lets create a dummy node to simplify the code
	struct ListNode dummy;
	dummy.next = NULL;

	// A pointer to track the end of the result list
	struct ListNode* tail = &dummy;

	// Lets define a carry variable.
	int carry = 0;

	// Loop until both lists are exhausted and there is no carry left
	while (l1 != NULL || l2 != NULL || carry != 0) {
		// Get the values from l1 and l2, if the node is NULL, use 0
		int x = (l1 != NULL) ? l1->val : 0;
		int y = (l2 != NULL) ? l2->val : 0;

		int sum = x + y + carry;

		// We should get the digit and carry
		int digit = sum % 10;
		carry = sum / 10;

		// Lets create a new node
		struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = digit;
		newNode->next = NULL;
		
		// Add the new node to the end of the result list
		tail->next = newNode;
		tail = tail->next;

		// Move to the next nodes in l1 and l2
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}

	// Return the next of dummy node which is the head of the resultant list
	return dummy.next;
}