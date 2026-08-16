class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(a && b) {

            if(a->val <= b->val) {
                curr->next = a;
                a = a->next;
            }
            else {
                curr->next = b;
                b = b->next;
            }

            curr = curr->next;
        }

        if(a)
            curr->next = a;
        else
            curr->next = b;

        return dummy->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return nullptr;

        return solve(lists, 0, lists.size() - 1);
    }


    ListNode* solve(vector<ListNode*>& lists, int left, int right) {

        if(left == right)
            return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* first = solve(lists, left, mid);
        ListNode* second = solve(lists, mid + 1, right);

        return mergeTwoLists(first, second);
    }
};