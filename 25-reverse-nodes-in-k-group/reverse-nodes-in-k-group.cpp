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
    int getLength(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        int len = getLength(head);
        if(len < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        int pos = 0;

        while(pos<k){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            pos++;
        }

        ListNode* recHead = reverseKGroup(curr, k);
        head -> next = recHead;
        return prev;
    }
};