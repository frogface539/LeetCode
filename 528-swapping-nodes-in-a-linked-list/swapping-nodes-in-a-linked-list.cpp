class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while(head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int length = getLength(head);

        ListNode* first = head;
        for(int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;
        for(int i = 1; i <= length - k; i++) {
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};
