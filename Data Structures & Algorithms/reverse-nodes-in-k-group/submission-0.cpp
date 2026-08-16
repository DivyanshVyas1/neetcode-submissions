class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Check whether k nodes are available
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr)
                return head;
            temp = temp->next;
        }

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // head is now the tail of reversed group
        head->next = reverseKGroup(curr, k);

        // prev is the new head
        return prev;
    }
};