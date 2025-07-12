/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Step 1: Count the nodes
        int count = 1;
        ListNode* tail = head;
        while (tail->next) {
            count++;
            tail = tail->next;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find the new tail (count - k % count - 1 steps)
        k = k % count;
        int stepsToNewTail = count - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle and set new head
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
