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
    ListNode* middle(ListNode* head){
        if(head == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;

        while(head != NULL){
            ListNode* curr = head;
            head = head->next;

            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return;
        }

        ListNode* mid = middle(head);
        ListNode* second = reverse(mid->next);

        mid->next = NULL;

        ListNode* first = head;

        while(first != NULL && second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};